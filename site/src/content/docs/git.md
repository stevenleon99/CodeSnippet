---
title: Git
description: Git basics and common operations.
---

Learn basic manipulation of Git.

## Git Clone

```bash
# Clone a specific branch
git clone -b [branch name] [url]

# Clone with submodules
git clone --recursive <url>

# Rename remote reference
git remote rename origin newname
```

## Git Commit

```bash
git init
git add --all  # or specify [filename]
git commit -m "Initial Commit"
git remote add origin <url>
git push -u origin master
```

## Git Checkout

```bash
# Create and switch to new branch
git checkout -b [branchname]

# Switch to existing branch
git checkout [branchname]
```

## Git Push

```bash
git push -u origin [branch]
# -u sets upstream so future git push/pull works without arguments
```

## Git Tag

```bash
git tag [tagname] && git push origin [branch] --tags
git tag -d [tagname]  # delete a tag
```

## Git Merge

```bash
git checkout [branchname] && git merge [branchA] [branchB]
```

## Git Rebase

```bash
# Interactive rebase
git rebase -i <commit_hash>

# Squash commits since commit A
# Change all but first commit from 'pick' to 'squash'
```

## Git Restore

```bash
# Unstage a file (introduced in 2.23.0)
git restore --staged <file>
# Same as: git reset HEAD <file>
```
