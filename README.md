# Git install and setup in the Bellagio Server



1) Create a new directory for your Git repository by running the following command:

```
mkdir myrepo.git
cd myrepo.git
```
Initialize the directory as a Git repository by running the following command:

```
git init --bare
```

This command will create a new Git repository in the myrepo.git directory.

3. Set up access to your Git repository. There are two ways to set up access: SSH and HTTPS.

    SSH:

Generate an SSH key pair on your local machine using the command: 
```
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```
Make sure to replace your_email@example.com with your email address used for your Git account.

Copy the public key to the remote server by the following steps:

1. Look for the public key in your repo.git repository.
2. Cat this file and copy it into the clipboard. 
3. Go to gitHub, your account settings and the `SSH and GPG` tab. Select `New SSH key` and paste your public key there.

Return to your remote repository and run the ssh agent to register your private key. You will need to do the following 2 steps every time you start a new session on the Bellagio server.

Start the ssh-agent by running the following command:
```
eval $(ssh-agent -s)
```
Add your private key to the ssh-agent by running the following command:

```
ssh-add /path/to/private/key
```
This should log you into the remote server without requiring a password. 

Clone the Git repository to your local machine using the command:

```
git clone git@github.com:Computer-Science-135/Collab_assignment.git
```
This will add all of the files in the github master branch into your local repository.

---

You will need to create a local branch to work from and this will then appear in gitub when you push your files there for review.

Create a new branch in your Git repository, you can use the following command:
```
git branch new-branch-name
```
Switch to the new branch you just created, you can use the following command:
```
git checkout new-branch-name // Do not add "/origin" to this
```

You will now see the files from the master branch duplicated here. 

You can add or create files or edit the current files that were pulled over from the master branch.

When you make changes you will need to add them to be tracked.
```
git add .
```
This starts the git tracking of that file. 
Now you need to take a snapshot of the file so that there is a record of its current state. Use the commit command. Add a message to describe the changes.

```
git commit -m "Commit message"
```

Push the new branch to the remote repository: Use the git push command with the --set-upstream option to push the new branch to the remote repository and set the upstream to track the branch. 

```
git push --set-upstream origin <new-branch-name>
```

Now you will see your branch in the Github repository and all other team members will be able to make comments. 

After this, every time you make changes that you want to have reviewed, you can push those changes to the remote branch.

```
git push <remote-name> <new-branch-name>
```

Make sure you have the latest changes from the remote GitHub branch. You can do this by running the command. 
```
git pull origin branch-name.
```

    
Verify the push: You can verify that the new branch has been pushed to the remote repository by visiting the repository on Github or by using the git branch -r command.
```
git branch -r
```

Run the following command to see a list of all the branches in your local Git repository:
```
git branch
```




If you want to commit only one file in your Git branch, you can use the following command:

```
git add file-name
```

If you want to see a summary of the changes that have been added, you can use the following command instead:
```
git status
```

You can use the git log and git diff commands to see the changes made to files in a repository. --follow, follows across renames.

```
git log --follow file-name
```

The git diff command shows the differences between two commits or two branches. To see the changes made to a specific file, you can use the following command:
```
git diff  file-name
```

