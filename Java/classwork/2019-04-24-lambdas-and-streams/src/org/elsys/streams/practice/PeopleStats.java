package org.elsys.streams.practice;

import java.util.IntSummaryStatistics;
import java.util.List;

public class PeopleStats {

    public static IntSummaryStatistics getStats(List<Person> people) {
        IntSummaryStatistics statistics = new IntSummaryStatistics();
        people.stream()
                .map(Person::getAge) // person -> person.getAge()
                .forEach(statistics::accept); // integer -> statistics.accept(integer)

        return statistics;
    }
}