package org.elsys.streams.practice;

import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class Kids {

    public static Set<String> getKidNames(List<Person> people) {
        return people.stream()
                .filter(person -> person.getAge() <= 18)
                .map(kid -> kid.getName())
                .collect(Collectors.toSet());
    }

    public static Map<String, Integer> getKidsAgeByName(List<Person> people) {
<<<<<<< Updated upstream
        return null;
=======
        return people.stream()
                .filter(person -> person.getAge() <= 18)
                .collect(Collectors.toMap(
                        person -> person.getName(),
                        person -> person.getAge()
                ));
>>>>>>> Stashed changes
    }

}
