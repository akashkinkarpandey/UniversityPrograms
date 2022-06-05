def print_subjects(*list_of_subjects):
    print("Subjects are")
    for x in list_of_subjects:
        print(x,end=" ")
    print()
a=list(map(str,input("Enter all subjects name in single line:-").split()))
print_subjects(a)
