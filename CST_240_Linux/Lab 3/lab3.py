import os
import subprocess

exe = {} # dictionary to hold keys: file order, and values: file name and location

while True:
    print("\n--- Choose One ---")
    print("Dir: To find files in current directory")
    print("Dir <directory name>: To find files in a given directory")
    print("Run <number>: To run files in the most recent directory")
    print("Exit")

    choice = input("Enter Input: \n")
    parts = choice.split()

    # FIRST COMMAND: TO ACCESS CURRENT DIRECTORY
    if len(parts) == 1 and parts[0].lower() == "dir":
        cwd = os.getcwd()

        result = subprocess.run(["ls", "-l", cwd],
                                capture_output=True,
                                text=True)

        lines = result.stdout.splitlines()
        exe.clear()  # clear the dictionary before writing to it
        exeCounter = 0

        for line in lines:
            words = line.split()

            if len(words) < 9:
                continue

            permissions = words[0]
            name = words[-1]

            if permissions[0] != "d" and "x" in permissions[3]:
                exeCounter += 1
                exe[exeCounter] = os.path.join(cwd, name)
                print(str(exeCounter) + ") " + name)

    # SECOND COMMAND: TO ACCESS GIVEN DIRECTORY
    elif len(parts) == 2 and parts[0].lower() == "dir":
        directory = os.path.expanduser(parts[1])

        if os.path.isdir(directory):
            result = subprocess.run(["ls", "-l", directory],
                                    capture_output=True,
                                    text=True)

            lines = result.stdout.splitlines()
            exe.clear()
            exeCounter = 0

            for line in lines:
                words = line.split()

                if len(words) < 9:
                    continue

                permissions = words[0]
                name = words[-1]

                if permissions[0] != "d" and "x" in permissions[3]:
                    exeCounter += 1
                    exe[exeCounter] = os.path.join(directory, name)
                    print(str(exeCounter) + ") " + name)
        else:
            print("Invalid directory!")

    # THIRD COMMAND: TO RUN THE PROGRAMS FROM THE CURRENT OR GIVEN DIRECTORY
    elif len(parts) == 2 and parts[0].lower() == "run":
        if len(exe) == 0:
            print("No directory results saved. Run dir first!")

        elif not parts[1].isdigit():
            print("Invalid run number!")

        else:
            fileValue = int(parts[1])

            if fileValue not in exe:
                print("Number not found in dir list!")
            else:
                fileName = exe[fileValue]
                print("Running File: " + fileName)
                subprocess.run([fileName])

    # FOURTH COMMAND: TO EXIT THE PROGRAM
    elif len(parts) == 1 and parts[0].lower() == "exit":
        break

    else:
        print("Invalid option, try again!")
