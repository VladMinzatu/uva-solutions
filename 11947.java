import java.util.GregorianCalendar;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main{
	
	public static void main(String[] args){
		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line = br.readLine();
			int N = Integer.parseInt(line.trim());
			for(int i = 0; i < N; i++)
			{
				line = br.readLine();
				int month = Integer.parseInt(line.substring(0, 2));
				int day = Integer.parseInt(line.substring(2, 4));
				int year = Integer.parseInt(line.substring(4, 8));
				GregorianCalendar cal = new GregorianCalendar(year, month - 1, day);
				cal.add(GregorianCalendar.DATE, 280);
				String sign = getSign(cal);
				
				String monthPrefix = "";
				if(cal.get(GregorianCalendar.MONTH) + 1 < 10)
					monthPrefix = "0";
				String dayPrefix = "";
				if(cal.get(GregorianCalendar.DAY_OF_MONTH) < 10)
					dayPrefix = "0";
				System.out.println((i + 1) + " " + monthPrefix + (cal.get(GregorianCalendar.MONTH) + 1) + "/" + dayPrefix + cal.get(GregorianCalendar.DAY_OF_MONTH) + "/" + cal.get(GregorianCalendar.YEAR) + " " + sign);				  
			}
		}catch(IOException exception){
			exception.printStackTrace();
		}
	}

	public static String getSign(GregorianCalendar cal){
		int day = cal.get(GregorianCalendar.DAY_OF_MONTH);
		switch(cal.get(GregorianCalendar.MONTH)){
			case 0: if(day < 21)
					return "capricorn";
				else
					return "aquarius";	
			case 1: if(day < 20)
                                        return "aquarius";
                                else
                                        return "pisces";
			case 2: if(day < 21)
                                        return "pisces";
                                else
                                        return "aries";
			case 3: if(day < 21)
                                        return "aries";
                                else
                                        return "taurus";
			case 4: if(day < 22)
                                        return "taurus";
                                else
                                        return "gemini";
			case 5: if(day < 22)
                                        return "gemini";
                                else
                                        return "cancer";
			case 6: if(day < 23)
                                        return "cancer";
                                else
                                        return "leo";
			case 7: if(day < 22)
                                        return "leo";
                                else
                                        return "virgo";
			case 8: if(day < 24)
                                        return "virgo";
                                else
                                        return "libra";
			case 9: if(day < 24)
                                        return "libra";
                                else
                                        return "scorpio";
			case 10: if(day < 23)
                                        return "scorpio";
                                else
                                        return "sagittarius";
			default: if(day < 23)
                                        return "sagittarius";
                                else
                                        return "capricorn";
		}
	}
}
