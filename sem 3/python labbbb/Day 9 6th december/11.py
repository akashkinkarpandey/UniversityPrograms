import sys
#0-th index of argv contains file path
program_path=sys.argv[0]
#file name is written after the last backslash in program_path
#rfind returns last occurence of a element
index_of_backslash=program_path.rfind("\\") 
#file name starts after index of backslash so we add 1
program_name=program_path[index_of_backslash+1:]
command_line_arguments=sys.argv[1:]#extracting the cmd line arguments
count=len(command_line_arguments)
print("Program name is ",program_name)
for value,item in enumerate(command_line_arguments):
    print(f"{value}-th command line argument is {item}")
print("Number of command line arguments are ",count)

