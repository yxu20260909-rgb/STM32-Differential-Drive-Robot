# Git + GitHub 操作手册（STM32 项目专用）

> 适用环境：Windows / Git Bash / Keil / Proteus  
> 仓库：[`YXU20260909-RGB/STM32-Differential-Drive-Robot`](https://github.com/YXU20260909-RGB/STM32-Differential-Drive-Robot)

## 📖 导航

- [一、理解 Git 和 GitHub](#一理解-git-和-github)
- [二、日常开发：只需记住这几步](#二日常开发只需记住这几步)
- [三、新项目第一次上传](#三新项目第一次上传)
- [四、Keil 与 Proteus 文件管理](#四keil-与-proteus-文件管理)
- [五、常用命令速查](#五常用命令速查)
- [六、我们实际遇到过的问题](#六我们实际遇到过的问题)
- [七、每次提交的检查清单](#七每次提交的检查清单)

## 一、理解 Git 和 GitHub

| 名称 | 作用 | 记忆方式 |
|---|---|---|
| Git | 在电脑本地记录代码版本 | 本地版本记录器 |
| Git Bash | 在 Windows 上执行 Git 命令 | 命令窗口 |
| GitHub | 远程托管和展示代码仓库 | 网上项目主页 |
| Commit | 保存一个本地版本 | 存档 |
| Push | 把本地提交上传 GitHub | 上传 |
| Pull | 同步 GitHub 上的更新 | 拉取 |

```mermaid
flowchart LR
    A[Keil / Proteus 修改文件] --> B[git add 暂存]
    B --> C[git commit 本地存档]
    C --> D[git push 上传 GitHub]
```

> **重点：** `git commit` 只保存到本地，**`git push` 才会上传到 GitHub**。

## 二、日常开发：只需记住这几步

打开**已有仓库的根目录**（里面应有隐藏的 `.git` 文件夹），在空白处右键打开 Git Bash：

```bash
git status
git add .
git diff --cached --stat
git commit -m "feat: add motor PWM control"
git push
```

含义：

1. `git status`：确认在哪个仓库，有哪些文件改变。
2. `git add .`：将需要提交的改动放到暂存区；**执行前检查是否有不相关文件**。
3. `git diff --cached --stat`：核对本次将要提交哪些文件。
4. `git commit -m "..."`：写清本次完成的内容并保存本地版本。
5. `git push`：上传到自己的 GitHub 仓库（第一次需要设置上游分支，见下文）。

### 推荐提交信息

| 前缀 | 用途 | 示例 |
|---|---|---|
| `feat` | 新增功能 | `feat: add encoder speed measurement` |
| `fix` | 修复问题 | `fix: correct PWM polarity` |
| `docs` | 修改文档 | `docs: add PWM experiment notes` |
| `refactor` | 重构代码 | `refactor: extract motor driver module` |
| `test` | 补充测试 | `test: record PID step response` |

## 三、新项目第一次上传

> **本仓库已经完成以下初始化步骤，以后继续开发时不要反复执行 `git init` 或 `git remote add origin`。** 本节供建立新仓库时参考。

### ① 在 GitHub 新建仓库

在 [GitHub 新建仓库页面](https://github.com/new) 创建仓库。若已有本地工程，首次可以先不勾选生成 README，以减少分支合并步骤。

### ② 在本地工程根目录打开 Git Bash

```bash
pwd    # 查看当前文件夹
ls     # 查看文件
cd ..  # 返回上一级
```

### ③ 初始化版本管理

```bash
git init -b main
```

### ④ 建立 `.gitignore`

```bash
notepad .gitignore
```

此文件用来排除 Keil 编译输出、Proteus 自动备份、个人设置等。保存以后先查看文件是否正确，再提交。

### ⑤ 提交第一个版本

```bash
git status
git add .
git diff --cached --stat
git commit -m "feat: add initial STM32 PWM project"
```

如果 Git 提示 `Author identity unknown`，先配置提交身份（邮箱请填自己的 GitHub 已验证邮箱或 GitHub 提供的 noreply 邮箱）：

```bash
git config --global user.name "你的 GitHub 用户名"
git config --global user.email "你的提交邮箱"
```

### ⑥ 关联仓库并首次上传

```bash
git remote add origin https://github.com/YXU20260909-RGB/STM32-Differential-Drive-Robot.git
git remote -v
git push -u origin main
```

如果弹出浏览器身份验证，请完成 GitHub 登录/授权（不要把验证码或令牌发给别人）。

### ⑦ 网页验收

打开 [仓库主页](https://github.com/YXU20260909-RGB/STM32-Differential-Drive-Robot)，确认能看到代码文件及提交记录。

## 四、Keil 与 Proteus 文件管理

| 文件类型 | 通常如何处理 | 原因 |
|---|---|---|
| `*.c`、`*.h` | ✅ 保留 | 源码和头文件 |
| `*.uvprojx` | ✅ 保留 | Keil 项目配置 |
| `*.pdsprj` | ✅ 保留**本项目正式仿真工程** | Proteus 主工程 |
| `Objects/`、`Listings/` | 🚫 一般忽略 | Keil 编译输出 |
| `*.uvoptx` | 🚫 一般忽略 | Keil 用户本地配置 |
| `Project Backups/` | 🚫 一般忽略 | Proteus 自动备份 |
| `*.one` | 🚫 目前忽略 | 私人 OneNote 笔记 |

**当前仓库的特殊情况：** `2 Proteus/` 里混有旧项目，所以暂时在 `.gitignore` 中排除整个目录：

```gitignore
/2 Proteus/
**/Project Backups/
```

后续制作新的电机控制仿真时，建议单独整理一个只含本项目的仿真目录，再追踪其 `.pdsprj`、必要模型与固件。不要简单删除原电脑目录。

**注意：** `.gitignore` 只阻止新文件被自动跟踪；对于**已经提交过**的文件，还需要在适当的时候用 `git rm --cached` 移除跟踪。`--cached` 不会删掉本机原文件。

## 五、常用命令速查

| 命令 | 用途 |
|---|---|
| `git --version` | 检查是否安装 Git |
| `pwd`、`ls` | 检查当前目录与文件 |
| `git status` | 查看修改与分支情况 |
| `git status --short` | 简洁地列出变更 |
| `git add .` | 暂存当前目录及子目录的变更 |
| `git add README.md docs/` | 只暂存指定文件与目录 |
| `git diff` | 查看尚未暂存的具体修改 |
| `git diff --cached --stat` | 查看即将提交的文件统计 |
| `git commit -m "说明"` | 提交一个本地版本 |
| `git push` | 上传到远程仓库 |
| `git pull` | 拉取并合并远程更新 |
| `git log --oneline -5` | 查看最近 5 次提交 |
| `git remote -v` | 查看远程仓库地址 |
| `git ls-files` | 查看被 Git 跟踪的文件 |
| `git config core.quotepath false` | 改善中文路径的转义显示 |

## 六、我们实际遇到过的问题

### 问题 1：`bash: $'\E[200~git': command not found`

**原因：** 复制粘贴命令时，终端混入了控制字符。它不代表 Git 安装失败。

**解决：** 按 `Ctrl + C` 回到提示符，直接**手动输入**命令，不要把前面的 `$` 当成命令一部分。

### 问题 2：`fatal: not a git repository`

**原因：** 当前目录还没有 Git 仓库，或者没有进入项目根目录。

**检查：** `pwd` 和 `ls -a`。如果这是一个全新项目才执行 `git init -b main`，不要对已有仓库盲目重复初始化。

### 问题 3：`git status` 显示 `??` / `A` / `D`

| 标记 | 意义 |
|---|---|
| `??` | 未被 Git 跟踪的新文件 |
| `A` | 新加入暂存区的文件 |
| `D` | 被标记为删除/从版本移除的文件 |

`git rm -r --cached -- "2 Proteus"` 是**从 Git 跟踪中移除**该目录，而不是删除电脑里的文件。

### 问题 4：第一次提交误包含 Proteus 备份

如果**尚未推送到 GitHub**，可以调整 `.gitignore` 并清理暂存区，再使用：

```bash
git rm -r --cached -- "2 Proteus"
git add .gitignore
git commit --amend --no-edit
```

`--amend` 会改写最近一次提交。**不要对已经推送、与别人协作的提交照搬此操作**；通常应该另外做一次正常提交。

### 问题 5：身份验证成功但不知道是否上传

浏览器显示 `Authentication Succeeded` 仅说明身份认证已通过。回到 Git Bash 查看是否出现 `main -> main`；也可以刷新 GitHub 仓库页面核对文件。必要时重试 `git push`。

### 问题 6：`remote origin already exists`

说明已经有名为 `origin` 的远程仓库，先执行 `git remote -v` 检查。不要反复运行 `git remote add origin`。

### 问题 7：远程分支比本地更新

如果你直接在 GitHub 网页改了 README，回电脑后先检查 `git status`；工作区干净时，通常先 `git pull`，再继续提交和推送。**不要轻易 `git push --force`**。

## 七、每次提交的检查清单

- [ ] 代码至少完成编译检查；仿真结果与实际验证结果分开记录。
- [ ] 本次提交只包含计划中的功能/文档。
- [ ] 已检查 `git status` 与 `git diff --cached --stat`。
- [ ] 没有密码、令牌、个人笔记、无关工程和自动备份。
- [ ] `git commit` 说明清楚。
- [ ] `git push` 成功，网页能看到新提交。
- [ ] 已填写 [开发日志模板](开发日志模板.md)。

---

**一句话记住：改代码 → `git add` → `git commit` → `git push`。**
