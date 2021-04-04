string dayOfProgrammer(int year) {
    int days = 31, day, month;
    string date;
    days += 28;
    if(year<1918 && year%4 == 0)
        days += 1;
    else if(year==1918)
        days-=13;
    else if(year>1918 && (year%400==0 || (year%4==0 && year%100 != 0)))
        days+=1;
    month = 2;
    while(256 - days > 31){
        days += 31;
        month++;
        if(256 - days < 30)
            break;
        days += 30;
        month++;
    }
    day = 256-days-1;
    month++;
    if(day < 10)
        date = '0';
    date = date+to_string(day)+'.';
    if(month < 10)
        date = date+'0';
    date = date+to_string(month)+'.';
    date = date+to_string(year);
    return date;
}
