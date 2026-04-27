## 已完成任务文档
`workflow/done/260427-fix-lake-build.md` - 修复 `Leo-ed-Haskell` 分支 `numina/tri` 的 `lake build`

## 全局重要记忆
- Lean 文件应优先按需引入具体模块，避免直接 `import Mathlib` 这种 umbrella import；在磁盘或构建预算受限时，这能显著降低 `lake build` 的体积和失败风险。
