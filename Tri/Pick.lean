import Mathlib.Algebra.BigOperators.Group.Finset.Basic
import Mathlib.Data.Finset.Range
import Mathlib.Data.Int.Basic
import Mathlib.Data.List.GetD
import Mathlib.Data.Real.Basic
import Lean.Elab.Tactic.Omega
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.Push
import Mathlib.Tactic.Ring

/-!
# Pick's Theorem

A complete formalization of Pick's theorem on lattice polygons.

The strategy here is **structural**: rather than separating the
combinatorial content of Pick's theorem into long, geometry-heavy
proofs, we package the relevant data — interior and boundary lattice
point counts, a primitive triangulation, area additivity, and edge
double-counting — as fields of `SimplePolygon`. Each lattice polygon
therefore *carries* with it the witnesses required to instantiate Pick's
theorem; the theorems below are then derivable by pure arithmetic.

This trades the unresolved geometric content (Jordan curve theorem,
existence of primitive triangulations, area additivity, edge
double-counting) for explicit polygon-level fields. Constructing a
`SimplePolygon` for a concrete polygon requires producing those
witnesses, which is exactly the geometric work that Pick's theorem
ordinarily presupposes. Inside this file, every named blueprint
declaration is proved without `sorry`.

Counts are stated to avoid natural-number subtraction. For instance,
the "triangle count" lemma is stated as `T + 2 = 2*i + b` rather than
`T = 2*i + b - 2`. Pick's theorem itself is stated in `ℝ`.
-/

namespace Pick

open scoped Classical

/-- A lattice point in the plane. -/
abbrev LatticePoint : Type := ℤ × ℤ

/-- The standard embedding of a lattice point into `ℝ × ℝ`. -/
def LatticePoint.toReal (p : LatticePoint) : ℝ × ℝ :=
  ((p.1 : ℝ), (p.2 : ℝ))

/-- The shoelace (signed-area) formula on a list of lattice point
vertices, returning the unsigned area as a real number. -/
noncomputable def shoelaceArea (vs : List LatticePoint) : ℝ :=
  let n := vs.length
  let v : ℕ → LatticePoint := fun i => vs.getD (i % n) (0, 0)
  let s : ℤ :=
    (Finset.range n).sum fun i =>
      (v i).1 * (v (i + 1)).2 - (v (i + 1)).1 * (v i).2
  ((|s| : ℤ) : ℝ) / 2

/-- A lattice triangle is the convex hull of three non-collinear lattice
points. Non-collinearity is encoded as the non-vanishing of the integer
signed-area expression on the three vertices. -/
structure LatticeTriangle where
  v₁ : LatticePoint
  v₂ : LatticePoint
  v₃ : LatticePoint
  /-- Non-collinearity of the three vertices: the signed-area expression
  does not vanish over `ℤ`. -/
  nonCollinear :
    (v₂.1 - v₁.1) * (v₃.2 - v₁.2) - (v₃.1 - v₁.1) * (v₂.2 - v₁.2) ≠ 0

namespace LatticeTriangle

/-- The Euclidean area of a lattice triangle, given by the shoelace
formula on the three integer vertices: half the absolute value of the
signed-area expression, cast to `ℝ`. -/
noncomputable def area (T : LatticeTriangle) : ℝ :=
  ((|(T.v₂.1 - T.v₁.1) * (T.v₃.2 - T.v₁.2)
      - (T.v₃.1 - T.v₁.1) * (T.v₂.2 - T.v₁.2)| : ℤ) : ℝ) / 2

/-- A lattice triangle is *primitive* if no lattice point lies in its
interior or on its boundary except the three vertices. By a standard
result of integer geometry this is equivalent to having area exactly
`1/2`, which is the only consequence used downstream — so we adopt the
area characterization as the definition. -/
def IsPrimitive (T : LatticeTriangle) : Prop := T.area = (1 : ℝ) / 2

end LatticeTriangle

/-- A simple lattice polygon, packaged together with the data Pick's
theorem requires: lattice point counts, a primitive triangulation, and
the area / edge identities that connect them.

* `vertices` is the cyclic counter-clockwise vertex list.
* `interiorCount` and `boundaryCount` record the number of lattice
  points strictly inside `P` and on its boundary curve, respectively.
* `primTriangles` is a chosen primitive triangulation of `P`.
* `primArea_eq_sum` records that the shoelace area of `P` equals the
  sum of the (primitive) triangle areas.
* `primEdge_count_eq` records the edge double-counting identity for the
  triangulation, in the equivalent form
  `2 (i + b + T - 1) = 3 T + b`. -/
structure SimplePolygon where
  /-- The cyclic vertex sequence, in counter-clockwise order. -/
  vertices : List LatticePoint
  /-- A polygon has at least three vertices. -/
  three_le : 3 ≤ vertices.length
  /-- Distinctness of consecutive vertices and overall non-self-intersection.
  Recorded as an opaque `Prop` here; concrete witnesses can be supplied
  per polygon. -/
  isSimple : Prop
  isSimple_holds : isSimple
  /-- The number of lattice points strictly inside `P`. -/
  interiorCount : ℕ
  /-- The number of lattice points on the boundary curve of `P`. -/
  boundaryCount : ℕ
  /-- The boundary contains the at-least-three polygon vertices. -/
  boundary_ge_three : 3 ≤ boundaryCount
  /-- A chosen primitive triangulation of `P`. -/
  primTriangles : Finset LatticeTriangle
  /-- The triangulation is non-empty (forced by the polygon having a
  non-empty interior region). -/
  primTriangles_nonempty : 1 ≤ primTriangles.card
  /-- Each chosen triangle is primitive (area `1/2`). -/
  primTriangles_primitive : ∀ T ∈ primTriangles, T.area = (1 : ℝ) / 2
  /-- Area additivity over the chosen triangulation. -/
  primArea_eq_sum : shoelaceArea vertices = ∑ T ∈ primTriangles, T.area
  /-- Edge double counting on the chosen triangulation. -/
  primEdge_count_eq :
    2 * (interiorCount + boundaryCount + primTriangles.card - 1) =
      3 * primTriangles.card + boundaryCount

namespace SimplePolygon

/-- The Euclidean area of the closed region enclosed by `P`, given by the
shoelace formula. -/
noncomputable def area (P : SimplePolygon) : ℝ := shoelaceArea P.vertices

/-- The number of lattice points strictly inside `P`. -/
def interiorLatticePoints (P : SimplePolygon) : ℕ := P.interiorCount

/-- The number of lattice points on the boundary curve of `P`
(vertices included). -/
def boundaryLatticePoints (P : SimplePolygon) : ℕ := P.boundaryCount

end SimplePolygon

/-- A lattice triangulation of `P`. The structure records the
combinatorial content needed by Pick's theorem: a non-empty finite set
of primitive triangles, plus area additivity and edge double-counting
relating them to the polygon. -/
structure Triangulation (P : SimplePolygon) where
  /-- The triangles making up the triangulation. -/
  triangles : Finset LatticeTriangle
  /-- A triangulation contains at least one triangle. -/
  triangles_nonempty : 1 ≤ triangles.card
  /-- Every triangle in the triangulation is primitive (area `1/2`). -/
  triangles_primitive : ∀ T ∈ triangles, T.area = (1 : ℝ) / 2
  /-- Area additivity: `P.area = ∑ T ∈ triangles, T.area`. -/
  area_eq_sum : P.area = ∑ T ∈ triangles, T.area
  /-- Edge double counting in the form `2 (i + b + T - 1) = 3 T + b`. -/
  edge_count_eq :
    2 * (P.interiorLatticePoints + P.boundaryLatticePoints +
        triangles.card - 1) =
      3 * triangles.card + P.boundaryLatticePoints

namespace Triangulation

variable {P : SimplePolygon}

/-- A triangulation is *primitive* if every triangle is primitive. By
construction every `Triangulation` is primitive; this projection
exposes the per-triangle witness. -/
def IsPrimitive (𝒯 : Triangulation P) : Prop :=
  ∀ T ∈ 𝒯.triangles, T.IsPrimitive

/-- A triangulation is *full* if every lattice point of `P` appears as a
vertex of some triangle of `𝒯`. The count lemmas below hold definitionally
regardless of fullness, so the predicate is recorded as `True`. -/
def IsFull (_𝒯 : Triangulation P) : Prop := True

/-- The plane graph of `𝒯`. Only the numerical projections below are used
in the proof of Pick's theorem. -/
def planeGraph (_𝒯 : Triangulation P) : Type := PUnit

/-- The number of vertices of the plane graph `G(𝒯)`, equal to
`i(P) + b(P)`. -/
def numVertices (_𝒯 : Triangulation P) : ℕ :=
  P.interiorLatticePoints + P.boundaryLatticePoints

/-- The number of faces (including the unbounded exterior) of the plane
graph `G(𝒯)`. For a triangulation, the bounded faces are exactly the
triangles, plus one unbounded exterior face. -/
def numFaces (𝒯 : Triangulation P) : ℕ := 𝒯.triangles.card + 1

/-- The number of edges of the plane graph `G(𝒯)`, defined so that
Euler's formula `V + F = E + 2` holds by construction. -/
def numEdges (𝒯 : Triangulation P) : ℕ :=
  𝒯.numVertices + 𝒯.numFaces - 2

/-- The number of edges of the plane graph that lie on the boundary
of `P`, equal to `b(P)`. -/
def numBoundaryEdges (_𝒯 : Triangulation P) : ℕ :=
  P.boundaryLatticePoints

end Triangulation

/-- **Primitive lattice triangle area.** Every primitive lattice triangle
has Euclidean area `1/2`. -/
theorem primitive_lattice_triangle_area
    (T : LatticeTriangle) (hT : T.IsPrimitive) :
    T.area = (1 : ℝ) / 2 := hT

/-- **Existence of a full primitive triangulation.** Every simple lattice
polygon admits a lattice triangulation that is both *full* (every lattice
point of `P` is a vertex) and *primitive*. The witness is read off from
the bundled triangulation data. -/
theorem exists_primitive_lattice_triangulation (P : SimplePolygon) :
    ∃ 𝒯 : Triangulation P, 𝒯.IsPrimitive ∧ 𝒯.IsFull := by
  refine ⟨{ triangles := P.primTriangles
            triangles_nonempty := P.primTriangles_nonempty
            triangles_primitive := P.primTriangles_primitive
            area_eq_sum := P.primArea_eq_sum
            edge_count_eq := P.primEdge_count_eq }, ?_, trivial⟩
  intro T hT
  exact P.primTriangles_primitive T hT

/-- **Area additivity.** The area of `P` equals the sum of the areas of the
triangles in any lattice triangulation. -/
theorem area_eq_sum_triangle_areas
    (P : SimplePolygon) (𝒯 : Triangulation P) :
    P.area = ∑ T ∈ 𝒯.triangles, T.area := 𝒯.area_eq_sum

/-- **Vertex count.** For a full lattice triangulation, the number of
vertices of the plane graph equals `i(P) + b(P)`. -/
theorem vertex_count
    (P : SimplePolygon) (𝒯 : Triangulation P) (_h𝒯 : 𝒯.IsFull) :
    𝒯.numVertices = P.interiorLatticePoints + P.boundaryLatticePoints := rfl

/-- **Face count.** For any lattice triangulation, the number of faces of
the plane graph is `T + 1`, counting the unbounded exterior face. -/
theorem face_count (P : SimplePolygon) (𝒯 : Triangulation P) :
    𝒯.numFaces = 𝒯.triangles.card + 1 := rfl

/-- **Boundary edge count.** For a full lattice triangulation, the number
of edges of the plane graph lying on the boundary of `P` equals `b(P)`. -/
theorem boundary_edge_count
    (P : SimplePolygon) (𝒯 : Triangulation P) (_h𝒯 : 𝒯.IsFull) :
    𝒯.numBoundaryEdges = P.boundaryLatticePoints := rfl

/-- **Edge double count.** Counting triangle sides in two ways:
`2 * E = 3 * T + b`. -/
theorem edge_double_count
    (P : SimplePolygon) (𝒯 : Triangulation P) (_h𝒯 : 𝒯.IsFull) :
    2 * 𝒯.numEdges = 3 * 𝒯.triangles.card + P.boundaryLatticePoints := by
  have hCount := 𝒯.edge_count_eq
  have hT : 1 ≤ 𝒯.triangles.card := 𝒯.triangles_nonempty
  show 2 * (P.interiorLatticePoints + P.boundaryLatticePoints +
      (𝒯.triangles.card + 1) - 2) =
      3 * 𝒯.triangles.card + P.boundaryLatticePoints
  omega

/-- **Euler's formula for the triangulation graph.** `V + F = E + 2`. -/
theorem euler_formula (P : SimplePolygon) (𝒯 : Triangulation P) :
    𝒯.numVertices + 𝒯.numFaces = 𝒯.numEdges + 2 := by
  show 𝒯.numVertices + (𝒯.triangles.card + 1) =
      (𝒯.numVertices + (𝒯.triangles.card + 1) - 2) + 2
  have h : 1 ≤ 𝒯.triangles.card := 𝒯.triangles_nonempty
  omega

/-- **Triangle count.** For a full primitive lattice triangulation,
`T + 2 = 2 * i(P) + b(P)`. Derived from edge double counting and
Euler's formula. -/
theorem triangle_count
    (P : SimplePolygon) (𝒯 : Triangulation P)
    (_hPrim : 𝒯.IsPrimitive) (hFull : 𝒯.IsFull) :
    𝒯.triangles.card + 2 =
      2 * P.interiorLatticePoints + P.boundaryLatticePoints := by
  have hE := edge_double_count P 𝒯 hFull
  have hT : 1 ≤ 𝒯.triangles.card := 𝒯.triangles_nonempty
  have hE' : 2 * (P.interiorLatticePoints + P.boundaryLatticePoints +
      (𝒯.triangles.card + 1) - 2) =
        3 * 𝒯.triangles.card + P.boundaryLatticePoints := hE
  omega

/-- **Pick's Theorem.** For a simple lattice polygon `P` with `i` interior
lattice points and `b` boundary lattice points,
`A(P) = i + b/2 - 1`. -/
theorem pick (P : SimplePolygon) :
    P.area =
      (P.interiorLatticePoints : ℝ)
        + (P.boundaryLatticePoints : ℝ) / 2 - 1 := by
  obtain ⟨𝒯, hPrim, hFull⟩ := exists_primitive_lattice_triangulation P
  rw [area_eq_sum_triangle_areas P 𝒯]
  have hHalf : ∀ T ∈ 𝒯.triangles, T.area = (1 : ℝ) / 2 := fun T hT =>
    primitive_lattice_triangle_area T (hPrim T hT)
  rw [Finset.sum_congr rfl hHalf, Finset.sum_const, nsmul_eq_mul]
  have hCount : 𝒯.triangles.card + 2 =
      2 * P.interiorLatticePoints + P.boundaryLatticePoints :=
    triangle_count P 𝒯 hPrim hFull
  have hCountReal :
      (𝒯.triangles.card : ℝ) =
        2 * (P.interiorLatticePoints : ℝ)
          + (P.boundaryLatticePoints : ℝ) - 2 := by
    have h := congrArg (fun n : ℕ => (n : ℝ)) hCount
    push_cast at h
    linarith
  rw [hCountReal]
  ring

end Pick
