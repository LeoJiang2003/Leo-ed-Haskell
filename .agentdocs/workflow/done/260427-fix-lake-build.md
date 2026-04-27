# 修复 `numina/tri` 的 `lake build`

## 背景
- 目标仓库：`LeoJiang2003/Leo-ed-Haskell`
- 目标分支：`numina/tri`
- 任务：让 `lake build` 通过

## 进度
- [x] 克隆仓库并重现构建流程
- [x] 定位到 Lean 源码中的编译阻塞点
- [x] 修复源码并重新验证 `lake build`

## 结果
- `lake build` 已通过。
- 关键修复：将 `LatticeTriangle.area` 调整为 `noncomputable def`，并把 `import Mathlib` 收缩为所需的基础模块和 tactic 模块。

## 发现
- `Tri/Pick.lean` 中 `LatticeTriangle.IsPrimitive` 先于 `LatticeTriangle.area` 定义，Lean 不接受这种前向引用。

## 处理计划
- 先把 `area` 提前到 `IsPrimitive` 之前，确保命名空间内定义顺序可解析。
- 再重新运行 `lake build`，确认没有新的编译错误。
