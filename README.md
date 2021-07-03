# Cyrex's Cathook Fork
![banner](http://i.imgur.com/w96wdtE.png)
[![CircleCI](https://circleci.com/gh/pogpoggers/cathook.svg?style=svg)](https://circleci.com/gh/pogpoggers/cathook) <- (circleci status for our fork) 

## Risk of VAC detection

The software could be detected by VAC in the future. Only use it on accounts you won't regret getting VAC banned.

## Overview

Cathook is a bot hunting software designed for Team Fortress 2 for Linux. Cathook includes some joke features like

* Only aimbot other cathook users
* Vote NO if a cheater is trying to kick a human player
* Vote YES to votes created by human players
* Auto abandon game if someone calls a votekick on you
* Log the Steam ID's of other Cathook users for educational purposes
* Encrypted chat
* Nullnexus Support (Find other Cathook users in-game automatically)
* Chance to get manually VAC banned by Valve

and a lot of useful features, including

* Working hitscan nospread
* Anti Backstab with option to use "No" voice command when spy tries to backstab you
* Extremely customizable spam (you can make spam lines that'll include name of random dead enemy pyro or sniper)
* Follow Bots
* Navparser Bots (Walkbots that can walk on any map without manual configuration)
* Working crit hack (Editors note: Not fully working on all weapons)
* Backtrack
* Automatic matchmaking
* And many more features!

[FULL LIST OF FEATURES HERE](https://cathook.club/wikis/Feature-List-and-explanations)

## Hosting anti-bot bots

You can host multiple antibot-bots on your computer or server just like all other bots
Visit [the catbot repo](https://github.com/cyrexlinuz/catbot-setup) for more information.

# Installing, updating, attaching (injecting)
Cathook is tested on Ubuntu, Manjaro and Arch. It's guaranteed that, Cathook will work on these distros.

You first need to get "git" 
On Ubuntu, you can basically run:
sudo apt-get install git -y

git clone https://github.com/cyrexlinuz/cathook

cd cathook

scripts/developer (First y and then n)

./update (If it asks for auto updater, SET IT TO NO.)

When installation completes, you can start the TF2 first and then run:

sudo ./attach

It should start working
If you have any questions, you can always contact me from Telegram: @cyrexlinuz

## Reporting Issues

If some things doesn't work as expected, please open issues on GitHub here.

## Contributing

Do you want to submit code to cathook? Please read `CONTRIBUTING.md` for a short introduction.
