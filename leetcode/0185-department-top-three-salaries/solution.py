import numpy as np
import pandas as pd

def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    join_df = pd.merge(employee, department, left_on='departmentId', right_on="id")
    
    result = pd.DataFrame()
    for depart in np.unique(join_df['name_y']):
        seg_df = join_df[join_df['name_y'] == depart]
        top_salaries = np.sort(list(set(seg_df['salary'])))[-3:]
        
        indices = seg_df['salary'].apply(lambda s: s in top_salaries)
        result = pd.concat([result, seg_df[indices]])

    if len(result) != 0:
        result = result[['name_y', 'name_x', 'salary']]
        result.columns = ['Department', 'Employee', 'Salary']
    else:
        result = pd.DataFrame({
            'Department': [],
            'Employee': [],
            'Salary': []
        })

    return result
