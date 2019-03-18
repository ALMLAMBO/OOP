package org.elsys;

import java.util.Objects;

public final class Employee {

    private final String name;
    private final long id;

    public Employee(String name, long id) {
        this.name = name;
        this.id = id;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                ", id=" + id +
                '}';
    }

    @Override
    public final boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Employee)) return false;
        Employee employee = (Employee) o;
        return id == employee.id &&
                Objects.equals(name, employee.name);
    }

    @Override
    public final int hashCode() {
        return Objects.hash(name, id);
    }

    public long getId() {
        return id;
    }
}