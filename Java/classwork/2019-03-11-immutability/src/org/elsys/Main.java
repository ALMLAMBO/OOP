package org.elsys;

import java.lang.reflect.Field;
import java.math.BigDecimal;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        String val;
        BigDecimal decimal = new BigDecimal("3.341235656345643654");
        HashSet<Employee> employees = new HashSet<>();
        employees.add(new Employee("Petkan", 1));
        Employee ivan2 = new Employee("Ivan", 2);
        employees.add(ivan2);
        System.out.println(employees);
        //setId(ivan2, 1);
        System.out.println(employees);
        //employees.add(new EmployeeHackChild("Ivan", 4));
        //employees.add(new EmployeeHackChild("Ivan", 5));
        System.out.println(employees);
        System.out.println(decimal);
    }

    private static void setId(Employee ivan2, long id) {
        try {
            //can use also ivan2.getClass()
            Field field = Employee.class.getDeclaredField("id");
            field.setAccessible(true);
            field.set(ivan2, id);
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }
    }
}