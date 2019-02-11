package org.elsys;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Student veso = new Student
                (1, "Veselin", "Rusinov");
        ArrayList<Student> students = new ArrayList<>();
        students.add(veso);
        System.out.println(students.toString());
        students.add(new Student
                (2, "Ivan", "Ivanov"));
        System.out.println(students.contains(new Student
                (1, "Veselin", "Rusinov")));
    }
}
