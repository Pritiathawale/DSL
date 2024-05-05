size = int(input("Enter the table size: "))
n = int(input("\nEnter no. of records to be inserted: "))
hash_table=[-1]*size
def linear_probing(telephone_no):
    for i in range(size):
        index=(telephone_no+i)%size
        if(hash_table[index]==-1):
            hash_table[index]=(telephone_no)
            print("Record Inserted\n")
            break
    else:
        print("Table Full, Record cannot be inserted")
def quadratic_probing(telephone_no):
    i=0
    for i in range(size):
        index=(telephone_no%size + i*i)%size
        if(hash_table[index]==-1):
            hash_table[index]=(telephone_no)
            print("Record Inserted\n")
            break
        else:
            i+=1
            if(i==size):
                print("Element cannot be inserted")
def search(telephone_no):
    count=1
    for i in range(size):
        index=(telephone_no+i)%size
        if(hash_table[index]==telephone_no):
            print("Element Found at index ",index)
            print("Required record: ",hash_table[index])
            print("No. of comparisons= ",count)
            break
        elif(hash_table[index]!=telephone_no):
            i+=1
            count+=1
    else:
        print("Record not found")
def display():
    print("Index        Telephone number")
    for i in range(size):
        if (hash_table[i]!= -1):
            print(i, "          ",hash_table[i])
while(True):
    choice = int(input("\n1. Insert Record using Linear Probing\n2. Insert Record using Quadratic Probing\n3. Search Record\n4. Display Records\n5. Exit\nEnter your choice:"))
    if(choice==1):
        for i in range(n):
            telephone_no= int(input("\nEnter the telephone_no: "))
            linear_probing(telephone_no)
    elif(choice==2):
        for i in range(n):
            telephone_no= int(input("\nEnter the telephone_no: "))
            quadratic_probing(telephone_no)
    elif(choice==3):
        telephone_no=int(input("\nEnter telephone no to be searched: "))
        search(telephone_no)
    elif(choice==4):
        display()
    else:
        print("Program Exited")
        exit(0)


