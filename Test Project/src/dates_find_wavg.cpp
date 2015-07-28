void find_wavg(Date fromDate, Date toDate)
{
    if(is_same_period(fromDate,toDate))
    {
        int qtr = get_current_qtr(fromDate.getMonth());
        cout << "Quarter Q" << qtr << " and wavg=100%" << endl;
        return;
    }
    //dates span across more than 1 qtr
    int tot_days    = daysBetween(fromDate,toDate);
    int days_left   = days_until_qtr_end(fromDate);     // days left until current quarter end.
    int days_after  = days_after_qtr_start(toDate);     // days passed after current quarter start

    if( (days_left + days_after) == tot_days)
    {
        // the 2 dates span across just 1 quarter
        int qtr1 = get_current_qtr(fromDate.getMonth());
        int qtr2 = get_current_qtr(toDate.getMonth());
        cout << "Quarter Q" << qtr1 << " and wavg=" << (days_left/tot_days)*100 << "%" << endl
             << "Quarter Q" << qtr2 << " and wavg=" << (days_after/tot_days)*100 << "%" << endl;
    }
    else
    {
        Date curr_dt = fromDate;
        // move curr_dt a quarter at a time, while printing every quarter we encounter
        while(curr_dt <= toDate)
        {
            days_left       = days_until_qtr_end(curr_dt);
            int qtr         = get_current_qtr(curr_dt.getMonth());
            cout << "Quarter Q" << qtr << " and wavg=" << (days_left/tot_days)*100 << "%" << endl;
            // update curr_dt to point to start of next quarter
            // where "days_left" is the number of days until quater end
            // and the "+ 1" is to push it to start of next quarter
            curr_dt.setDate(curr_dt.getDate() + days_left + 1);
        }
        // this means we have moved curr_dt past the toDate
        // ie all quarters and wavg's until the en_dt have been handled.
        // We only need to account for the number of days en_dt is past its current quarter
        int qtr     = get_current_qtr(toDate.getMonth());
        cout << "Quarter Q" << qtr << " and wavg=" << (days_after/tot_days)*100 << "%" << endl;
    }
}
