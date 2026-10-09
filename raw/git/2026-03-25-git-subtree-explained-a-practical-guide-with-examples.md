# Git Subtree Explained: A Practical Guide with Examples

> Source: https://www.datacamp.com/tutorial/git-subtree
> Collected: 2026-10-09
> Published: 2026-03-25

Author: Oluseye Jeremiah (DataCamp tutorial).

## What Is git subtree?

Git subtree includes another Git repository under a specific folder in your project while keeping its entire commit history. Unlike copying code or using symbolic links, subtree maintains a connection to the original repository so you can pull updates and push changes back.

Copy-pasting code means no connection to original repo, no update path when the library changes, and no history of where the code came from. With git subtree you get full commit history from the original repo, pull updates with a single command, push changes back to the original repo if needed, and everything lives in one repository checkout.

The key difference from Git submodules: subtree content is committed directly into your main repository. When someone clones your project, they get everything in one checkout with no extra setup steps.

## How git subtree Works

When you add a subtree, Git merges another repository's history into a subdirectory of your project:

1. Git fetches the remote repository's history
2. Git rewrites those commits so they appear under your chosen subdirectory
3. Git merges this rewritten history into your current branch
4. Future updates follow the same pattern fetch, rewrite, merge

Your repository contains actual files and full commit history from the subtree, not just a pointer or reference. When someone clones your project or checks out a branch, they immediately have all the code. There's no separate "initialize submodules" step.

The tradeoff: your repository grows because it contains both your code and the subtree's code plus its full history.

## How to Use git subtree (Common Commands)

Example setup: main project `data-pipeline`, shared library `shared-utils` at `https://github.com/yourteam/shared-utils.git`, included under `libs/shared-utils/`.

### git subtree add

The `add` command includes another repository into your project for the first time.

```
git subtree add --prefix=<directory> <remote-url> <branch> --squash
```

Real example:

```
git subtree add --prefix=libs/shared-utils \
  https://github.com/yourteam/shared-utils.git \
  main \
  --squash
```

What this does: creates the libs/shared-utils directory, copies all files from shared-utils into it, commits everything to your repository, and records the connection for future updates.

Flags:

- `--prefix=libs/shared-utils`: Where the subtree lives in your project. You must use the exact same prefix for all future operations.
- `--squash`: Combines all the subtree's commit history into a single commit in your project. This keeps your project's history cleaner. Without --squash, you'd see every commit from the original repo in your project's history. When to squash: Use --squash unless you need to preserve detailed commit attribution from the original repo.

After running this, you'll see a new commit in your project with a message like "Add 'libs/shared-utils/' from commit 'abc123'".

### git subtree pull

The pull command updates your subtree with changes from the original repository.

```
git subtree pull --prefix=<directory> <remote-url> <branch> --squash
```

Real example:

```
git subtree pull --prefix=libs/shared-utils \
  https://github.com/yourteam/shared-utils.git \
  main \
  --squash
```

What this does: fetches new commits from the remote repository, merges them into your libs/shared-utils directory, and creates a merge commit in your project.

The prefix must match exactly. Squash consistency: If you used --squash during add, you should use --squash for every pull. Mixing squashed and non-squashed updates creates confusing history.

Handling conflicts: If you've modified files in libs/shared-utils and those same files changed upstream, you'll get merge conflicts. Resolve them the same way you'd resolve any Git merge conflict.

### git subtree push

The push command sends changes you've made in the subtree folder back to the original repository.

```
git subtree push --prefix=<directory> <remote-url> <branch>
```

Real example:

```
git subtree push --prefix=libs/shared-utils \
  https://github.com/yourteam/shared-utils.git \
  main
```

What this does: extracts only the commits that affected libs/shared-utils, rewrites them as if they were made in the root of shared-utils, and pushes those commits to the original repository.

Think of push as the reverse of pull. Pull brings changes in; push sends changes out.

You need write access to the original repository. If you don't have permission, you'd need to fork the repo, push to your fork, and create a pull request.

### git subtree split

The split command extracts a subdirectory's history into its own branch.

```
git subtree split --prefix=<directory> -b <new-branch-name>
```

Real example:

```
git subtree split --prefix=libs/shared-utils -b shared-utils-extracted
```

What this does: creates a new branch containing only commits that affected libs/shared-utils. This branch looks like a standalone repository of just that directory. The original branch remains unchanged.

Common use cases: carving a library out of a monorepo, and publishing a subdirectory as its own project.

Example workflow creating a new standalone repo:

```
git subtree split --prefix=libs/shared-utils -b shared-utils-standalone
git remote add shared-utils-origin https://github.com/yourteam/shared-utils-new.git
git push shared-utils-origin shared-utils-standalone:main
```

## git subtree vs. submodule

Use `submodule` if you need exact version pinning, or if the repo size is constrained. If your team has mixed Git skills and you want simplicity, use `subtree`.

| Aspect | git subtree | git submodule |
| --- | --- | --- |
| Setup complexity | Medium (straightforward commands) | High (separate `init` step required) |
| Clone experience | Simple (one clone, everything works) | Complex (`clone` + `git submodule update --init`) |
| Repository size | Larger (includes full subtree content + history) | Smaller (just a pointer to another repo) |
| Developer onboarding | Easy (everything works after clone) | Harder (must understand submodule workflow) |
| CI/CD complexity | Simple (clone and go) | More complex (must initialize submodules) |
| Version pinning | Less precise (merges the latest or specific commit) | Precise (exact commit hash) |
| Update workflow | `git subtree pull` (merges changes) | `cd submodule && git pull` (manual) |
| Pushing changes back | `git subtree push` | Normal git push inside submodule |
| Separation of concerns | Mixed (code lives in main repo) | Clear (submodule is separate repo) |

Use git submodule when you need strict version pinning (must use exact commit X of library Y), clear separation between projects, multiple projects sharing the same dependency at different versions, or small main repository size.

Use git subtree when you want no extra initialization steps, new team members to clone once and then run tests, fewer Git concepts for your team to learn, or vendoring dependencies where you occasionally pull updates.

## When Not to Use git subtree

Don't use `git subtree` when repository size is a hard constraint. Subtree inflates your repo size because it includes full content and history.

Don't use `git subtree` if you need strict version pinning. You must use exactly version 2.3.1 of the library and nothing else. Submodules pin to exact commits; subtree merges ranges of commits.

Don't use `git subtree` if the external repo changes frequently. Constantly pulling updates creates a messy merge history. Consider whether a package manager would be cleaner.

Don't use `git subtree` if organizational separation is required. Different access controls, licensing, or ownership mean separate repositories make boundaries clearer.

## Advantages of git subtree

Single repository clone experience: Run git clone, and you're done. Everything you need is there.

Fewer moving parts than submodules: No separate initialization step. No detached HEAD states to explain. No "your submodule is out of sync" confusion.

CI/CD simplicity: clone and run tests, with no recursive-init step that breaks builds when forgotten.

Works well for teams with mixed Git comfort: they use familiar Git commands and everything works.

Good for vendoring with occasional updates: pull a bug-fix release in with one command, without constantly tracking upstream changes.

## Limitations and Tradeoffs of git subtree

Repository grows significantly: your repo contains both your code and the subtree's code plus its full commit history (unless you use --squash, which helps).

History graph complexity: Even with `--squash`, merge commits for subtree updates add complexity to your Git history.

Upstream divergence confusion: If you modify subtree files and upstream also changes them, merge conflicts happen.

Push workflow has gotchas: git subtree push needs to rewrite history, which can be slow for large subtrees.

Discipline required: Using different `--prefix` values or inconsistent `--squash` flags creates problems. The team needs to document and follow the same workflow.

## Common Mistakes When Using git subtree

Inconsistent use of --squash: squashed add but non-squashed pull gives a confusing history. Document the choice in your project README.

Wrong or changing prefix: pulling with `--prefix=libs/utils` after adding with `--prefix=libs/shared-utils` doesn't work because Git can't find the subtree. Use the exact same prefix every time.

Expecting subtree to behave like submodule: you cannot cd into the subtree directory and checkout versions, because subtree content is just files in your repo, not a separate Git repository.

Not documenting the workflow: record the remote URL, the --squash choice, and the push/pull commands in your README.

Modifying subtree files without planning: push useful changes back upstream, or accept merge conflicts when you later pull updates.

## Conclusion

Git subtree trades repository size and history complexity for workflow simplicity. New team members clone the repo and start working right away.
