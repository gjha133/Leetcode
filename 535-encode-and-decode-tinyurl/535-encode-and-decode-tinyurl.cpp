class Solution {
public:
    unordered_map<string, string>UrlToCode, codeToUrl;
    string alphanumeric, base;    
	//                   \U0001f53bs = secure = important! :)
    Solution(): base("https://tinyurl.com/"),
    alphanumeric("abcdefghijklmnopqrstuvwxyzAbCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") {
        srand(time(0)); // seed for random generator used by rand()
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // if encoded url already exists for a given longUrl (dont want duplicates for same url)
        if(UrlToCode.count(longUrl)) return base + UrlToCode[longUrl];
        string code = "";
        // generate a random code from alphanumeric string
        while(1){
            for(int i = 0; i < 6; i++)
                code += alphanumeric[rand() % 62];
            // if new code is formed, break out of loop
            if(!codeToUrl.count(code)) break; 
            code = "";   // loop back to generate a new unique code
        }
        string encoded = base + code;
        UrlToCode[longUrl] = code;    // store longUrl to code mapping to avoid duplicates        
        codeToUrl[encoded] = longUrl; // to decode shortened url back to original
        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return codeToUrl[shortUrl];
    }
};