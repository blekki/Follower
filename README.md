# Follower
An ultra tiny project on how dots follow the cursor.

## Installation

Use the next command to clone the repository:
```shell
git clone https://github.com/blekki/Follower.git
```

Install all dependities, if you don't have them already. If you use Linux, you can try this commands:
```shell
sudo apt update
sudo apt install libglfw3-dev
sudo apt install cmake
```

Next step you need to build the project.
```shell
make
```

After all you can run the project on your personal computer.
```shell
make run
```

## Instruction

As default the simulation is freeze. Use the selected key to run it!

### Key binding

Various keys to control a simualtion.

| key | command |
| --- | ------- |
| `Space` | - stop/run a simulation. |
| `Esc` | - Close an application |

### Make commands

List of the commands for everyone who wants understand or rewrite the project.
| command | description |
| ------- | ----------- |
| `make` or `make all` | - Prepare the project to the correct work (build and compile). |
| `make build` | - Build the project. Process stops if the `./build` folder already exists.|
| `make rebuild` | - Forcibly rebuild. Recreate the `./build` folder. Be careful with this command. |
| `make rm-build` | - remove the `./build` folder and everything inside. |
| `make compile` | - Compile the project. |
| `cd ./build && make` | - The same as previously command. |
| `make run` | - Run the project binary file. |