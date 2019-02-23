package org.elsys;

import java.security.*;
import java.util.Scanner;

//link:
//https://www.hackerrank.com/contests/elsys-java-exercise-1-11a/challenges/java-int-to-string

public class IntToString {
    public static void main(String[] args) {
        DoNotTerminate.forbidExit();
        try {
            Scanner scanner = new Scanner(System.in);
            int n = Integer.parseInt(scanner.nextLine());
            scanner.close();
            String s = Integer.toString(n);
            if (n == Integer.parseInt(s)) {
                System.out.println("Good job");
            }
            else {
                System.out.println("Wrong answer.");
            }
        }
        catch(DoNotTerminate.ExitTrappedException e) {
            System.out.println("Unsuccessful attempt");
        }
    }
}

class DoNotTerminate {
    public static class ExitTrappedException
            extends SecurityException {
        public static final long serialVersionUID = 1;
    }

    public static void forbidExit() {
        final SecurityManager securityManager = new SecurityManager() {
            @Override
            public void checkPermission(Permission permission) {
                if(permission.getName().contains("exitVM")) {
                    throw new ExitTrappedException();
                }
            }
        };
        System.setSecurityManager(securityManager);
    }
}