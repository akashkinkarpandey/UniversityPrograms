def unlist(l): 
    ulist = [] 
    [ulist.append(x) for x in l if x not in ulist] 
    return ulist 
a = input("Enter the sentence:") 
a = ' '.join(unlist(a.split())) 
print(a)