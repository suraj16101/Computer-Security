import java.util.HashMap;
import java.util.Scanner;


public class Question3a
{
    public static void main(String args[])
    {
        String letter="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int shift=7;

        HashMap<String, String> Hash = new HashMap<>();

        for(int i=0;i<letter.length();i++)
        {
            int ascii=letter.charAt(i) + shift;
            if(ascii>90)
                ascii=ascii-26;


            String key=String.valueOf((char)(ascii));
            Hash.put(key,String.valueOf(letter.charAt(i)));

        }

        Scanner sc=new Scanner(System.in);

        String crypt=sc.next();
        crypt+=sc.nextLine();

        String decrypt="";

        for(int j=0;j<crypt.length();j++)
        {
            char val=crypt.charAt(j);
            String temp=Hash.get(""+Character.toUpperCase(val));
            if(temp!=null)
            {
                if (Character.isLowerCase(val))
                    decrypt += String.valueOf(temp).toLowerCase();

                else
                    decrypt += String.valueOf(temp);
            }
            else
            {
                decrypt+=val;
            }

        }
        System.out.println(decrypt);
    }
}
