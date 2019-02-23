package org.elsys;

import java.io.*;
import java.util.Calendar;

class Result {
    public static String findDay(int month, int day, int year) {
        Calendar c = Calendar.getInstance();
        c.set(year, month - 1, day);
        String resultDay = "";
        switch(c.get(Calendar.DAY_OF_WEEK)) {
            case 1:
                resultDay = "SUNDAY";
                break;
            case 2:
                resultDay = "MONDAY";
                break;
            case 3:
                resultDay = "TUESDAY";
                break;
            case 4:
                resultDay = "WEDNESDAY";
                break;
            case 5:
                resultDay = "THURSDAY";
                break;
            case 6:
                resultDay = "FRIDAY";
                break;
            case 7:
                resultDay = "SATURDAY";
                break;
        }
        return resultDay;
    }
}

public class DateAndTime {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader =
                new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter =
                new BufferedWriter(
                new FileWriter(
                System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader
                .readLine()
                .replace("\\s+$", "")
                .split(" ");

        int month = Integer.parseInt(firstMultipleInput[0]);
        int day = Integer.parseInt(firstMultipleInput[1]);
        int year = Integer.parseInt(firstMultipleInput[2]);

        String res = Result.findDay(month, day, year);
        bufferedWriter.write(res);
        bufferedWriter.newLine();
        bufferedReader.close();
        bufferedWriter.close();
    }
}