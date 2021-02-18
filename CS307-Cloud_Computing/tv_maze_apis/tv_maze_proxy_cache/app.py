#!/usr/local/bin/python3.8
import flask
import requests

import web_cache

app = flask.Flask(__name__)
app.config['DEBUG']

BASE_URL = 'http://api.tvmaze.com'
CACHE = web_cache.WebCache()


def response_or_cache(url):
    '''Handler for returning cached requests or new requests if url is uncached.

    Args:
        url (str): url pointing to tv_maze api endpoint.
    
    Returns:
        dict: JSON response that is new, cached, or an error.
    '''
    if url in CACHE:
        return CACHE[url]
    else:
        request = requests.get(url)
        if request.ok:
            CACHE[url] = flask.jsonify(request.json())
            return CACHE[url]
        else:
            bad_api_call = flask.jsonify(success=False)
            CACHE[url] = bad_api_call
            return CACHE[url]


@app.route('/search/shows')
def show_search():
    shows = flask.request.args.get('q')
    url = '{base}/search/shows?q={shows}'.format(base=BASE_URL, shows=shows)
    return response_or_cache(url)


@app.route('/singlesearch/shows')
def single_show_search():
    shows = flask.request.args.get('q')
    embed = flask.request.args.get('embed')
    print(embed)
    url = '{base}/singlesearch/shows?q={shows}'.format(base=BASE_URL, shows=shows)
    if embed is not None:
        url = '{url}&embed={embed}'.format(url=url, embed=embed)
    return response_or_cache(url)


@app.route('/lookup/shows')
def show_lookup():
    id = None
    id_type = None
    possible_query_params = ['tvrage', 'thetvdb', 'imdb']
    for param in possible_query_params:
        id = flask.request.args.get(param)
        if id is not None:
            id_type = param
            break
    url = '{base}/lookup/shows?{id_type}={id}',format(base=BASE_URL, id_type=id_type, id=id)
    return response_or_cache(url)


@app.route('/search/people')
def people_search():
    people = flask.request.args.get('q')
    url = '{base}/search/people?q={people}'.format(base=BASE_URL, people=people)
    return response_or_cache(url)


@app.route('/schedule')
def schedule():
    country_code = flask.request.args.get('country')
    date = flask.request.args.get('date')
    url = '{base}/schedule?'.format(base=BASE_URL)
    if country_code is not None:
        url = '{url}country={country_code}'.format(url=url, country_code=country_code)
    url = '{url}&'.format(url=url)
    if date is not None:
        url = '{url}date={date}'.format(url=url, date=date)
    return response_or_cache(url)


@app.route('/schedule/full')
def full_schedule():
    url = '{base}/schedule/full'.format(base=BASE_URL)
    return response_or_cache(url)


@app.route('/shows/<id>')
def show_main_info(id):
    embed = flask.request.args.get('embed')
    url = '{base}/shows/{id}'.format(base=BASE_URL, id=id)
    if embed is not None:
        url = '{url}/{embed}'.format(url=url, embed=embed)
    return response_or_cache(url)


@app.route('/shows/<id>/episodes')
def show_episode_list(id):
    specials = flask.request.args.get('specials')
    url = '{base}/shows/{id}/episodes?'.format(base=BASE_URL, id=id)
    if specials is not None:
        url = '{url}specials={specials}'.format(url=url, specials=specials)
    return response_or_cache(url)


@app.route('/shows/<id>/episodebynumber')
def episode_by_number(id):
    season = flask.request.args.get('season')
    number = flask.request.args.get('number')
    url = '{base}/shows/{id}/episodebynumber?season={season}&number={number}'.format(
        base=BASE_URL, id=id, season=season, number=number
    )
    return response_or_cache(url)


@app.route('/shows/<id>/episodesbydate')
def episodes_by_date(id):
    date = flask.request.args.get('date')
    url = '{base}/shows/{id}/episodesbydate?date={date}'.format(
        base=BASE_URL, id=id, date=date
    )
    return response_or_cache(url)


@app.route('/shows/<id>/seasons')
def show_seasons(id):
    url = '{base}/shows/{id}/seasons'.format(base=BASE_URL, id=id)
    return response_or_cache(url)


@app.route('/seasons/<id>/episodes')
def season_episodes(id):
    url = '{base}/seasons/{id}/episodes'.format(base=BASE_URL, id=id)
    return response_or_cache(url)


@app.route('/shows/<id>/cast')
def show_cast(id):
    url = '{base}/shows/{id}/cast'.format(base=BASE_URL, id=id)
    return response_or_cache(url)


@app.route('/shows/<id>/crew')
def show_crew(id):
    url = '{base}/shows/{id}/crew'.format(base=BASE_URL, id=id)
    return response_or_cache(url)


@app.route('/shows/<id>/akas')
def show_akas(id):
    url = '{base}/shows/{id}/akas'.format(base=BASE_URL, id=id)
    return response_or_cache(url)


@app.route('/shows/<id>/images')
def show_images(id):
    url = '{base}/shows/{id}/images'.format(base=BASE_URL, id=id)
    return response_or_cache(url)


@app.route('/shows')
def show_index():
    page = flask.request.args.get('page')
    url = '{base}/shows'
    if page is not None:
        url = '{url}?page={page}'.format(url=url, page=page)
    return response_or_cache(url)


@app.route('/episodes/<id>')
def episode_main_info(id):
    embed = flask.request.args.get('embed')
    url = '{base}/episodes/{id}'.format(base=BASE_URL, id=id)
    if embed is not None:
        url = '{url}?embed={embed}'.format(url=url, embed=embed)
    return response_or_cache(url)


@app.route('/people/<id>')
def person_main_info(id):
    embed = flask.request.args.get('embed')
    url = '{base}/people/{id}'.format(base=BASE_URL, id=id)
    if embed is not None:
        url = '{url}?embed={embed}'.format(url=url, embed=embed)
    return response_or_cache(url)


@app.route('/people/<id>/castcredits')
def person_cast_credits(id):
    embed = flask.request.args.get('embed')
    url = '{base}/people/{id}/castcredits'.format(base=BASE_URL, id=id)
    if embed is not None:
        url = '{url}?embed={embed}'.format(url=url, embed=embed)
    return response_or_cache(url)


@app.route('/people/<id>/crewcredits')
def person_crew_credits(id):
    embed = flask.request.args.get('embed')
    url = '{base}/people/{id}/crewcredits'.format(base=BASE_URL, id=id)
    if embed is not None:
        url = '{url}?embed={embed}'.format(url=url, embed=embed)
    return response_or_cache(url)


@app.route('/updates/shows')
def show_updates():
    url = '{base}/updates/shows'.format(base=BASE_URL)
    return response_or_cache(url)


if __name__ == '__main__':
    app.run(debug=True)