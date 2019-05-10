package org.elsys.streams.practice;

import java.util.List;
import java.util.stream.Collectors;

public class FilterCollection {

    public static List<String> transform(List<String> collection) {

        return collection.stream()
                .filter(s -> s.length() < 4)
                .collect(Collectors.toList());
    }
}
