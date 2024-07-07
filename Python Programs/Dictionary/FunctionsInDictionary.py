student = {
    "name" : "Ankit",
    "subjects" : {
        "physics" : 91,
        "chemistry" : 94,
        "math" : 96
    }
}

print(student.keys())
print(list(student.keys()))
print(len(student.keys()))
print(list(student.values()))
print(student.items())
print(list(student.items()))
print(student.get("name"))
print(student["name"])
student.update({"city" : " Katni"})
print(student)
newstudent = {"name" : "ansh", "age" : 16}
student.update(newstudent)
print(student)