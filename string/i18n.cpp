void printAll(string st) {
    cout << st[0] << st.size()-2 << st[st.size()-1] << endl;
    for(int i=st.size()-3; i>=1; i--) {
        for(int k=0; k<=st.size()-2-i; k++)
            cout << st.substr(0,k+1) << i << st.substr(i+k+1) << endl;
    }
    cout << st << endl;
}

 Will print out all word and char. input for eg: careercup. c7p, ca6p, etc
