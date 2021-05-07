#!/usr/bin/python3
"""[summary]

Returns:
    [type]: [description]
"""
import requests


def count_words(subreddit, word_list, hot_list_titles=[], after='null'):
    base_url = 'https://www.reddit.com/r/'
    url = base_url + subreddit + "/hot.json"
    credentials = {'User-Agent': "firefox"}
    parameters = {"limit": "100", "after": after}
    response = requests.get(url,
                            headers=credentials,
                            params=parameters,
                            allow_redirects=False)
    if response.status_code != 200:
        return None

    hot_list_of_dicts = response.json().get("data").get("children")
    after = response.json().get("data").get("after")
    hot_list_titles.extend([reddit.get("data").get("title") for
                            reddit in hot_list_of_dicts])
    if after is None:
        to_print_dict = {x: 0 for x in word_list}
        for word in word_list:
            count = 0
            for title in hot_list_titles:
                split_title = title.split()
                new_split = [element.lower() for element in split_title]
                count = count + new_split.count(word.lower())
            if count != 0:
                to_print_dict[word] = to_print_dict[word] + count

        for elem in sorted(to_print_dict.items(), key=lambda x: (-x[1], x[0])):
            if elem[1] != 0:
                print("{}: {}".format(elem[0], elem[1]))
    else:
        return count_words(subreddit, word_list,
                           hot_list_titles, after)