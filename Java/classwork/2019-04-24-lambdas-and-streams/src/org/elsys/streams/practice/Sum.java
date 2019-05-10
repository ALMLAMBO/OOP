package org.elsys.streams.practice;

import java.util.List;
import java.util.stream.Collectors;

public class Sum {

    public static int calculate(List<Integer> people) {
        return people.stream()
                .collect(Collectors.summingInt(p -> p.intValue()));
    }

}
