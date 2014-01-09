Example of basic ajax service:

```
curl -X POST -d '{"guid":"droutlook-2012-08-14"}' 'http://datasnapshots.nemac.com/data-snapshots/ajax'
```

The above request produces the following response:

```
{
    "node": {
        "about": "A knight ther was, and that a worthy man, that fro the tyme that he first bigan to ryden out, he loved chivalrye, trouthe and honour, fredom and curteisye.", 
        "day": "14", 
        "img": "http://datasnapshots-usdm-sample.nemac.com:8080/drought-usdm--2012-08-14--620.png", 
        "mon": "08", 
        "nid": "1364", 
        "year": "2012"
    }, 
    "request": {
        "guid": "droutlook-2012-08-14"
    }, 
    "user": {
        "cache": 0, 
        "hostname": "127.0.0.1", 
        "roles": {
            "1": "anonymous user"
        }, 
        "uid": 0
    }
}
```
