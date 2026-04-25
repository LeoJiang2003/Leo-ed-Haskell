import Mathlib

/-!
# Pick's Theorem

Sorry'd statement-level scaffolding for the `tri` blueprint. Every
definition and lemma in `numina/blueprints/tri/tri.tex` has a corresponding
declaration here. The mathematical content (predicates, area, lattice point
counts, triangulations, etc.) is left abstract: definitions return `sorry`
and propositions are stated as `True` placeholders only when the underlying
mathematical structure has not yet been chosen. Concrete predicates and
theorems will be filled in as the supporting infrastructure is built up.

Counts are stated to avoid natural-number subtraction. For instance, the
"triangle count" lemma is stated as `T + 2 = 2*i + b` rather than
`T = 2*i + b - 2`. Pick's theorem itself is stated in `ℝ`.
-/

namespace Pick

open scoped Classical

/-- A lattice point in the plane. -/
abbrev LatticePoint : Type := ℤ × ℤ

/-- The standard embedding of a lattice point into `ℝ × ℝ`. -/
def LatticePoint.toReal (p : LatticePoint) : ℝ × ℝ :=
  ((p.1 : ℝ), (p.2 : ℝ))

/-- A simple lattice polygon: a finite sequence of distinct lattice point
vertices (with at least three) whose closed polygonal curve does not
self-intersect, together with the closed bounded region it encloses.

The non-self-intersection predicate `isSimple` is left abstract for now
and will be refined as the supporting infrastructure is built. -/
structure SimplePolygon where
  /-- The cyclic vertex sequence, in counter-clockwise order. -/
  vertices : List LatticePoint
  /-- A polygon has at least three vertices. -/
  three_le : 3 ≤ vertices.length
  /-- Distinctness of consecutive vertices and overall non-self-intersection.
  Refined later. -/
  isSimple : Prop
  isSimple_holds : isSimple

namespace SimplePolygon

/-- The Euclidean area of the closed region enclosed by `P`, given by the
shoelace formula over consecutive cyclic vertex pairs. The integer signed
sum `∑ (xᵢ * yᵢ₊₁ - xᵢ₊₁ * yᵢ)` is taken over indices `i = 0, …, n-1`
with indices read modulo `n = vertices.length`; we then take its absolute
value, cast to `ℝ`, and divide by 2. -/
noncomputable def area (P : SimplePolygon) : ℝ :=
  let n := P.vertices.length
  let v : ℕ → LatticePoint := fun i => P.vertices.getD (i % n) (0, 0)
  let s : ℤ :=
    (Finset.range n).sum fun i =>
      (v i).1 * (v (i + 1)).2 - (v (i + 1)).1 * (v i).2
  ((|s| : ℤ) : ℝ) / 2

/-- The number of lattice points strictly inside `P`. -/
noncomputable def interiorLatticePoints (P : SimplePolygon) : ℕ := sorry

/-- The number of lattice points on the boundary curve of `P`
(vertices included). -/
noncomputable def boundaryLatticePoints (P : SimplePolygon) : ℕ := sorry

end SimplePolygon

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

/-- A lattice triangle is *primitive* if no lattice point lies in its
interior or on its boundary except the three vertices. -/
def IsPrimitive (T : LatticeTriangle) : Prop := sorry

/-- The Euclidean area of a lattice triangle, given by the shoelace
formula on the three integer vertices: half the absolute value of the
signed-area expression, cast to `ℝ`. -/
def area (T : LatticeTriangle) : ℝ :=
  ((|(T.v₂.1 - T.v₁.1) * (T.v₃.2 - T.v₁.2)
      - (T.v₃.1 - T.v₁.1) * (T.v₂.2 - T.v₁.2)| : ℤ) : ℝ) / 2

end LatticeTriangle

/-- A lattice triangulation of `P`: a finite collection of lattice
triangles, edge-to-edge, whose interiors are pairwise disjoint and whose
union equals the closed region `P`. The geometric predicates are left
abstract for now. -/
structure Triangulation (P : SimplePolygon) where
  /-- The triangles making up the triangulation. -/
  triangles : Finset LatticeTriangle
  /-- Their union equals the closed region `P`. -/
  unionEqP : Prop
  unionEqP_holds : unionEqP
  /-- Their interiors are pairwise disjoint. -/
  interiorsDisjoint : Prop
  interiorsDisjoint_holds : interiorsDisjoint
  /-- Edge-to-edge: distinct triangles meet in `∅`, a vertex, or an edge. -/
  edgeToEdge : Prop
  edgeToEdge_holds : edgeToEdge

namespace Triangulation

variable {P : SimplePolygon}

/-- A triangulation is *primitive* if every triangle is primitive. -/
def IsPrimitive (𝒯 : Triangulation P) : Prop :=
  ∀ T ∈ 𝒯.triangles, T.IsPrimitive

/-- A triangulation is *full* if every lattice point of `P` appears as a
vertex of some triangle of `𝒯`. -/
def IsFull (𝒯 : Triangulation P) : Prop := sorry

/-- The plane graph of `𝒯`. In this scaffolding only the numerical
projections `numVertices`, `numEdges`, `numFaces`, and `numBoundaryEdges`
are used; the underlying combinatorial object is left as a placeholder. -/
def planeGraph (_𝒯 : Triangulation P) : Type := PUnit

/-- The number of vertices of the plane graph `G(𝒯)`. -/
def numVertices (𝒯 : Triangulation P) : ℕ := sorry

/-- The number of edges of the plane graph `G(𝒯)`. -/
def numEdges (𝒯 : Triangulation P) : ℕ := sorry

/-- The number of faces (including the unbounded exterior) of the plane
graph `G(𝒯)`. -/
def numFaces (𝒯 : Triangulation P) : ℕ := sorry

/-- The number of edges of the plane graph that lie on the boundary
of `P`. -/
def numBoundaryEdges (𝒯 : Triangulation P) : ℕ := sorry

end Triangulation

/-- **Primitive lattice triangle area.** Every primitive lattice triangle
has Euclidean area `1/2`. -/
theorem primitive_lattice_triangle_area
    (T : LatticeTriangle) (hT : T.IsPrimitive) :
    T.area = (1 : ℝ) / 2 := by
  sorry

/-- **Existence of a full primitive triangulation.** Every simple lattice
polygon admits a lattice triangulation that is both *full* (every lattice
point of `P` is a vertex) and *primitive*. -/
theorem exists_primitive_lattice_triangulation (P : SimplePolygon) :
    ∃ 𝒯 : Triangulation P, 𝒯.IsPrimitive ∧ 𝒯.IsFull := by
  sorry

/-- **Area additivity.** The area of `P` equals the sum of the areas of the
triangles in any lattice triangulation. -/
theorem area_eq_sum_triangle_areas
    (P : SimplePolygon) (𝒯 : Triangulation P) :
    P.area = ∑ T ∈ 𝒯.triangles, T.area := by
  sorry

/-- **Vertex count.** For a full lattice triangulation, the number of
vertices of the plane graph equals `i(P) + b(P)`. -/
theorem vertex_count
    (P : SimplePolygon) (𝒯 : Triangulation P) (h𝒯 : 𝒯.IsFull) :
    𝒯.numVertices = P.interiorLatticePoints + P.boundaryLatticePoints := by
  sorry

/-- **Face count.** For any lattice triangulation, the number of faces of
the plane graph is `T + 1`, counting the unbounded exterior face. -/
theorem face_count (P : SimplePolygon) (𝒯 : Triangulation P) :
    𝒯.numFaces = 𝒯.triangles.card + 1 := by
  sorry

/-- **Boundary edge count.** For a full lattice triangulation, the number
of edges of the plane graph lying on the boundary of `P` equals `b(P)`. -/
theorem boundary_edge_count
    (P : SimplePolygon) (𝒯 : Triangulation P) (h𝒯 : 𝒯.IsFull) :
    𝒯.numBoundaryEdges = P.boundaryLatticePoints := by
  sorry

/-- **Edge double count.** Counting triangle sides in two ways:
`2 * E = 3 * T + b`. -/
theorem edge_double_count
    (P : SimplePolygon) (𝒯 : Triangulation P) (h𝒯 : 𝒯.IsFull) :
    2 * 𝒯.numEdges = 3 * 𝒯.triangles.card + P.boundaryLatticePoints := by
  sorry

/-- **Euler's formula for the triangulation graph.** `V + F = E + 2`. -/
theorem euler_formula (P : SimplePolygon) (𝒯 : Triangulation P) :
    𝒯.numVertices + 𝒯.numFaces = 𝒯.numEdges + 2 := by
  sorry

/-- **Triangle count.** For a full primitive lattice triangulation,
`T + 2 = 2 * i(P) + b(P)`. -/
theorem triangle_count
    (P : SimplePolygon) (𝒯 : Triangulation P)
    (hPrim : 𝒯.IsPrimitive) (hFull : 𝒯.IsFull) :
    𝒯.triangles.card + 2 =
      2 * P.interiorLatticePoints + P.boundaryLatticePoints := by
  sorry

/-- **Pick's Theorem.** For a simple lattice polygon `P` with `i` interior
lattice points and `b` boundary lattice points,
`A(P) = i + b/2 - 1`. -/
theorem pick (P : SimplePolygon) :
    P.area =
      (P.interiorLatticePoints : ℝ)
        + (P.boundaryLatticePoints : ℝ) / 2 - 1 := by
  sorry

end Pick
