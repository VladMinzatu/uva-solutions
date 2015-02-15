import java.util.GregorianCalendar;
import java.util.StringTokenizer;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main{

	public static void main(String[] args){
		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line;
			while(true){
				line = br.readLine();
				int days,day,month,year;
				StringTokenizer tokenizer = new StringTokenizer(line, " ");
				days = Integer.parseInt(tokenizer.nextToken());
				day = Integer.parseInt(tokenizer.nextToken());
				month = Integer.parseInt(tokenizer.nextToken());
				year = Integer.parseInt(tokenizer.nextToken());
				if(days + day + month + year == 0)
					break;
				GregorianCalendar cal = new GregorianCalendar(year, month - 1, day);
				cal.add(GregorianCalendar.DATE, days);
				System.out.println(cal.get(GregorianCalendar.DAY_OF_MONTH) + " " + (cal.get(GregorianCalendar.MONTH) + 1) + " " + cal.get(GregorianCalendar.YEAR));				  
			}
		}catch(IOException exception){
			exception.printStackTrace();
		}
	}
}
