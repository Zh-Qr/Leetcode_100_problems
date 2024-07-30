#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct Student {    // 学生结构体
    string name;    // 学生姓名
    int grade;      // 学生分数
    Student();  // 无参数构造函数
    Student(string nam, int grade) : name(nam), grade(grade) {};  // 有参数构造函数,后面是赋值
};

bool cmp(Student s1, Student s2) {  // 自定义排序
    if (s1.grade != s2.grade) {     // 如果学生成绩不同
        return s1.grade > s2.grade; // 则按照成绩降序排列
    }
    return s1.name < s2.name;   // 否则按照姓名升序排列
}

int main() {
    vector<Student> studs;
    // studs.emplace_back("Bob", 80);
    // studs.emplace_back("Ali", 90);
    // studs.emplace_back("Ann", 85);
    // studs.emplace_back("Liming", 90);
    // studs.emplace_back("Trump", 79);
    // studs.emplace_back("Fury", 58);
    // studs.emplace_back("Jam", 62);
    // studs.emplace_back("Lucy", 89);

    studs.push_back(Student("Bob", 80));
    studs.push_back(Student("Ali", 90));
    studs.push_back(Student("Ann", 85));
    studs.push_back(Student("Liming", 90));
    studs.push_back(Student("Trump", 79));
    studs.push_back(Student("Fury", 58));
    studs.push_back(Student("Jam", 62));
    studs.push_back(Student("Lucy", 89));

    sort(studs.begin(), studs.end(), cmp);  // 排序
    for (int i = 0; i < studs.size(); i++) {    // 输出结果
        cout << studs[i].name << "\t" << studs[i].grade << endl;
    }
    return 0;
}
