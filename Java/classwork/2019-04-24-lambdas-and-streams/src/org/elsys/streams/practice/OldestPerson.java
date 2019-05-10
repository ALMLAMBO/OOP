package org.elsys.streams.practice;

import java.util.Comparator;
import java.util.List;

public class OldestPerson {

    public static Person getOldestPerson(List<Person> people) {
        people.sort(Comparator.comparingInt(Person::getAge));
        //(p1, p2) -> p1.getAge() - p2.getAge()

        return people.get(people.size() - 1);
    }
}