def name_change(student, name):
    student[0] = name

name = ["Jiayu Li", 20]
name[0][0] = 'b'
name_change(name, "Sarah")
print(name)