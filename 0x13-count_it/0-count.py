#!/usr/bin/python3
"""[summary]

Returns:
    [type]: [description]
"""
import requests


def count_words(subreddit, word_list, hot_list_titles=[], after='null'):
    """[summary]

    Args:
        subreddit ([type]): [description]
        word_list ([type]): [description]
        hot_list_titles (list, optional): [description]. Defaults to [].
        after (str, optional): [description]. Defaults to 'null'.

    Returns:
        [type]: [description]
    """
    res = requests.get('https://www.reddit.com/r/' + subreddit + "/hot.json",
                       headers={
                           'User-Agent': "firefox"
                       },
                       params={
                           "limit": "100", "after": after
                       },
                       allow_redirects=False
                       )
    # if res.status_code != 200:
    #     return None
    data = res.json().get(
        "data"
    ).get(
        "children"
    )
    after = res.json(
    ).get(
        "data").get(
        "after")
    hot_list_titles.extend(
        [reddit.get("data"
                    ).get("title") for
         reddit in data])
    if after == None:
        data_dict = {
            x: 0 for x in word_list
        }
        for w in word_list:
            aux = 0
            for ob in hot_list_titles:
                aux_list = [x.lower() for x in ob.split()]
                aux += aux_list.count(w.lower())
            if aux != 0:
                data_dict[w] = data_dict[w] + aux
        for elem in sorted(data_dict.items(),
                           key=lambda x: (-x[1], x[0])
                           ):
            if elem[1] != 0:
                print("{}: {}".format(elem[0], elem[1]))
    else:
        return count_words(subreddit,
                           word_list,
                           hot_list_titles,
                           after)