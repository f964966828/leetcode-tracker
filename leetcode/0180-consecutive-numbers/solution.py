import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    prev = None
    numbers = []
    for data in logs.iloc:
        _, num = data
        if prev == num:
            count += 1
            if count == 3:
                numbers.append(num)
        else:
            prev = num
            count = 1

    return pd.DataFrame({
        'ConsecutiveNums': list(set(numbers))
    })
    
