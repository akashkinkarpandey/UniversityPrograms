student_dict = {'roll 1':
                {'name': 'akash',
                 'class': '10',
                 'subjects': ['history', 'geography', "science"]
                 },
                'roll 2':
                {'name': 'raghav',
                 'class': '12',
                 'subjects': ['bengali', 'hindi', "english"]
                 },
                'roll 3':
                {'name': 'samay',
                    'class': '12',
                    'subjects': ['maths', 'physics', 'chemistry']
                 },
                'roll 4':
                {'name': 'gourav',
                    'class': '12',
                    'subjects': ['biology', 'computer', 'drawing']
                 },
                'roll 5':
                {'name': 'gourav',
                    'class': '12',
                    'subjects': ['biology', 'computer', 'drawing']
                 },
                }
# roll 4 and roll 5 have same values so roll 5 is removed
keys = []
values = []
for k, v in student_dict.items():
    if v not in values:
        keys.append(k)
        values.append(v)

newdict = dict(zip(keys, values))

print(f"\tBefore removing duplicates,dictionary is {student_dict}\t")
print()
print(f"\tAfter removing duplicates,dictionary is {newdict}\t")
