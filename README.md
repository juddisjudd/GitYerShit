# GitYerShit
Simple tool to automate git pull and clone as well as build process for specifically [FiveM](https://fivem.net/) resources but could be altered for other use cases.

[VIDEO](https://www.youtube.com/watch?v=0jDLB9kfzFo)

# How To Use/How It Works:
Simply run the tool, it will ask you for your local directory (where you have your resources) then it will ask you for github username or org.
It will then check your "local directory" for sub folders match them with repos of the github username or org you provided and then proceed to git clone (if it's not already a git repo (aka contain .git folder), if it is a repo/has .git folder it will run git pull to try and update (it will inform you if the directories are up to date). 

Once the git pull/clone part is done it will ask you if you would like to check for package.json and build the resource if found. Currently this only will work correct if a resource uses a structure like [overextended](https://github.com/overextended) resources like **[ox_lib](https://github.com/overextended/ox_lib)\web** and will only using [pnpm](https://pnpm.io/) (for now).

If you choose no it will then ask if you could like to check another github username/org in which you can then go back and do the same process for other resources.

# Important
If you plan on building via Visual Studio make sure that you set "C++ Language Standard" to minimum **ISO C++20 Standard (/std:c++17)** (under Configuration Properties->C/C++).

## TODO
- [ ] Flush out process of automating building resources beyond "ox" resources that use "web" folder.
- [ ] Improve way of checking github repos and local directories.

#### I AM NOT PROVIDING SUPPORT FOR THIS TOOL AT THIS TIME.
