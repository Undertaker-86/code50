months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]
while True:
    try:
        us_format = input("Date: ").title().strip()

        # if us_format.isalnum() == False:
        #     raise ValueError

        if "/" in us_format:
            month, day, year = us_format.split("/")
            if month.isnumeric() == False:
                raise ValueError
        elif "," in us_format:
            month_day, year = us_format.split(",")
            year = year.strip()
            month, day = month_day.split(" ")
        else:
            raise ValueError

        if month in months:
            number = 1
            for index in months:

                if month == index:
                    month = number

                number += 1
        day = int(day)
        month = int(month)
        if int(day) > 31 or int(day) < 1 or int(month) > 12 or int(month) < 1:
            raise ValueError

        print(f"{year}-{month:02}-{day:02}", end = "")
        break

    except ValueError:
        pass


