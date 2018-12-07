import java.util.HashMap;
import java.util.Scanner;


public class Question3b
{
    public static void main(String args[])
    {
        String key="BIRDWATCHNGEFJKLMOPQSUVXYZ";
        String letter="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        HashMap<String, String> Hash = new HashMap<>();

        for(int i=0;i<letter.length();i++)
        {
            Hash.put(String.valueOf(key.charAt(i)),String.valueOf(letter.charAt(i)));
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
