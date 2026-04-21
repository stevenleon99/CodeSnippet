# Git
Learn basic manipulation of Git


### Git clone: 
- $ git clone -b [branch name] [url]Can be achieved by http or ssh (need to provide ssh key generated) It will generate a remote repository reference name `origin` Git remote rename origin newname (change the name of this argument: git config branch.master.remote)
- $ git clone --recursive <url> download the repository and its submodules locally

### Git commit
- % cd existing-project
- $ git init
- $ git add --all (or can select certain [filename])
- $ git commit -m "Initial Commit"
- $ git remote add origin ssh://git@stash.thcg.net:7999/ein-prod/documentation.git  (add the reference called origin to the remote repository)
- $ git push -u origin master (push to remote named origin branch named master and set the master as the upstreamer so that you can simply call git push/git pull in the future)

### Git checkout
- $ Git checkout -b [branchname] create another branch and switch to it
- $ Git checkout [branchname] switch to the branch
- Get variable name from git config
- $ git config branch.<master>[or other branch name].merge

### Git push
- $ git push -u origin testgit push <remote> <branch>

Branch test set up to track remote branch test from origin.

- $ git push -u origin master == git push origin master ; git branch --set-upstream master origin/masterOr you can force it to git config branch.master.remote origin
- $ git config branch.master.merge refs/heads/master

### Git pull
- $ git push <remote> <branch>

### Git tag
- $ Git tag [tagname] && git push origin test --tags (push the command with tagname)
- $ Git tag -d [tagname] -d deleteThe tag is linked with specific commit

### Git merge
- $ git checkout [branchname] && git merge [branchA] [branchB] [command sequence is used to merge branches locally]

### Git rebase
- $ git rebase -i <commit_hash> i: interactive mode, <> is the hash commit you want to base on
- $ git rebase -i A squash all commit since A
e.g.
pick 1234567 First commit
squash 2345678 Second commit
squash 3456789 Third commit
Modify the commit history: After running the command, Git will open an editor with a list of commits. The default action is pick for each commit. You should *change all but the first commit* you want to squash to squash (or s for short).
- git rebase origin/develop rebase onto the main branch (origin branch)


### Git reflog

### Git status

### Git restore
- is introduced in 2.23.0 to unstage a file
- git reset HEAD <file> and git restore --staged <file> are the same
