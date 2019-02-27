package org.elsys;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        ArrayList<Student> arrayList = new ArrayList<>();
        arrayList.add(
                new Student("Aleksander", "11A", 5.78));
        arrayList.add(
                new Student("Pesho", "11B", 5.45));
        arrayList.add(
                new Student("Gosho", "11V", 5.34));
        arrayList.add(
                new Student("Tosho", "11G", 5.20));

        School school = new School("TUES", arrayList);
        Map<String, List<Student>> map = school.getStudentsByClass();
        System.out.println(map.size());
        System.out.println(map);
    }
}