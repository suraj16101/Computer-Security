import datetime
import hashlib


def F(H):
    Value=H
    temp_otp=0
    OTP=0
    for loop in range(0,10):                        # Performing Continuous SHA-256 HASHING (10 times)
        Value="".join(reversed(Value))              # Reversing the Hash Value
        for i in range(0,len(Value)):               # Running the loop Length of Hash times(64 times)
            temp_otp+=ord(Value[i].upper())         # Converting the hash value to Capital and Adding the ASCII Value to form Temporary OTP
        temp_otp=str(temp_otp)                      # Converting this Temporary OTP to String OTP
        Value = hashlib.sha256(temp_otp.encode('utf-8')).hexdigest() # Performing SHA-256 Hashing on the String OTP
        if(loop==9):                                # Saving the last OTP generated
            OTP=temp_otp
        temp_otp=0

    OTP="".join((reversed(str(OTP))))               # Reversing the OTP
    return (int(OTP))                                    # Sending it to user



def OTP_generation():
    currentDT = datetime.datetime.now()  #Creating the string of date-time
    H = hashlib.sha256(str(currentDT).encode('utf-8')).hexdigest()  # Creating the string of date-time using SHA-256 function

    file = open("OTP.txt", "w")
    file.write(H)  # Writing in a File
    OTP = F(H)
    print(OTP)

OTP_generation()