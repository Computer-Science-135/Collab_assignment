# Collab_assignment
CS-135 Collaborative Assignment 
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

Copy the public key to the remote server by running:

```
ssh-copy-id user@server_ip_address
```
Start the ssh-agent by running the following command:
```
eval $(ssh-agent -s)
```
Add your private key to the ssh-agent by running the following command:
```
ssh-add /path/to/private/key

Replace user with your username and server_ip_address with the IP address of your server.


Clone the Git repository to your local machine using the command:

```
$ git clone git@github.com:Computer-Science-135/Collab_assignment.git
```
cd to the new cloned repository
```
Fetch the latest changes from the GitHub repository by running the following command:
```
git fetch
```
List all the available branches by running the following command:
```
git branch -a
```
Checkout the branch you want to work on by running the following command:
```
git checkout <branch-name>
```


