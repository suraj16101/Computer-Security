import hashlib

def F(H):
    Value=H
    temp_otp=0
    OTP=0
    for loop in range(0,10):                        # Performing Continuous SHA-256 HASHING (10 times)
        Value="".join(reversed(Value))              # Reversing the Hash Value
        for i in range(0,len(Value)):               # Running the loop Length of Hash times(64 times)
            temp_otp+=ord(Value[i].upper())         # Converting the hash value to Captial and Adding the ASCII Value to form Temporary OTP
        temp_otp=str(temp_otp)                      # Converting this Temporary OTP to String OTP
        Value = hashlib.sha256(temp_otp.encode('utf-8')).hexdigest() # Performing SHA-256 Hashing on the String OTP
        if(loop==9):                                # Saving the last OTP generated
            OTP=temp_otp
        temp_otp=0

    OTP="".join((reversed(str(OTP))))               # Reversing the OTP
    return (int(OTP))                               # Sending it to user


def OTP_generation():
    O=int(input("Enter the OTP - "))                 # Input from the user for OTP
    H=str([i for i in open("OTP.txt")][0])           # Input the Hash value from the File
    OTP_Correct = F(H)                               # Getting the actual OTP

    if(O==OTP_Correct):                              # Verifying the OTP
        print("Successful")
        open("OTP.txt", 'w').close()                 # Emptying the File
    else:
        print("Unsuccessful")

OTP_generation()