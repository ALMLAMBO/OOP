package org.elsys;

public class Student {
    private long id;
    private String FirstName;
    private String LastName;
    public Student() {
        this.id = 0;
        this.FirstName = this.LastName = "";
    }

    public Student(long id, String FirstName, String LastName) {
        this.id = id;
        this.FirstName = FirstName;
        this.LastName = LastName;
    }

    public long getId() {
        return id;
    }

    public String getFirstName() {
        return FirstName;
    }

    public String getLastName() {
        return LastName;
    }

    public void setId(long id) {
        this.id = id;
    }

    public void setFirstName(String firstName) {
        this.FirstName = firstName;
    }

    public void setLastName(String lastName) {
        this.LastName = lastName;
    }

    @Override
    public String toString() {
        return id
                + " " + FirstName
                + " " + LastName;
    }

    /*@Override
    public boolean equals(Student other) {

    }*/
}