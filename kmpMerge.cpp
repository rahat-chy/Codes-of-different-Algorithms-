#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

string merge(const string &pattern, const string &text){
	string s = pattern + '$' + text ;
	vector<int> pi(s.size()) ;

	pi[0] = 0 ;
	int j = 0 ;
	for(int i = 1 ; i < s.size() ; i++){
		while(j > 0 && s[i] != s[j])
			j = pi[j-1] ;
		if(s[i] == s[j])
			pi[i] = ++j ;
	}

    for(int i = 0 ; i < s.size() ; i++)
        if(pi[i] == pattern.size())
            return text ;

	return text + pattern.substr(pi.back());
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2, s3 ;
    while(cin >> s1 >> s2 >> s3){
        int ans = s1.size() + s2.size() + s3.size() ;
        ans = min(ans, (int) merge(s1, merge(s2, s3)).size() ) ;
        ans = min(ans, (int) merge(s1, merge(s3, s2)).size() ) ;
        ans = min(ans, (int) merge(s2, merge(s1, s3)).size() ) ;
        ans = min(ans, (int) merge(s2, merge(s3, s1)).size() ) ;
        ans = min(ans, (int) merge(s3, merge(s1, s2)).size() ) ;
        ans = min(ans, (int) merge(s3, merge(s2, s1)).size() ) ;
        cout << ans << endl ;
    }

    return 0;
}
