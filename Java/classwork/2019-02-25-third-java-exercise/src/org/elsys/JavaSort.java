package org.elsys;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

class Student{
    private int id;
    private String fname;
    private double cgpa;

    public Student(int id, String fname, double cgpa) {
        super();
        this.id = id;
        this.fname = fname;
        this.cgpa = cgpa;
    }

    public int getId() {
        return id;
    }

    public String getFname() {
        return fname;
    }

    public double getCgpa() {
        return cgpa;
    }
}

public class JavaSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfStudents = Integer.parseInt(scanner.nextLine());
        ArrayList<Student> studentsList = new ArrayList<>();

        for (int i = 0; i < numberOfStudents; i++) {
            int id = scanner.nextInt();
            String firstName = scanner.next();
            double cgpa = scanner.nextDouble();

            Student st = new Student(id, firstName, cgpa);
            studentsList.add(st);
        }

        studentsList.sort(new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                int result = Double.compare(o1.getCgpa(), o2.getCgpa());
                if(result != 0) {
                    return result;
                }
                int compareNames = o1.getFname().compareTo(o2.getFname());
                if(compareNames != 0) {
                    return compareNames;
                }
                return o1.getId() - o2.getId();
            }
        });

        for (Student student : studentsList) {
            System.out.println(student.getFname());
        }
    }
}