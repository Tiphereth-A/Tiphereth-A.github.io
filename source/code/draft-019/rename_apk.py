import os
from pyaxmlparser import APK


def get_new_filename(oldname):
    apk = APK(oldname)
    result = rf'{apk.application}-{apk.package}-{apk.version_name}({apk.version_code}).apk'
    # for Windows
    return result.translate(str.maketrans(r'\/:*?"<>|', '_'*9))


for dirpath, _, filenames in os.walk('.'):
    print(f'In "{dirpath}":')
    for filename in filter(lambda x: x.endswith('.apk') or x.endswith('.1'), filenames):
        try:
            oldname = os.path.join(dirpath, filename)
            new_filename = get_new_filename(oldname)
            if filename == new_filename:
                continue
            os.rename(oldname, os.path.join(dirpath, new_filename))
            print(f'\t"{filename}" -> "{new_filename}"')
        except FileExistsError:
            os.remove(oldname)
            print(f'\t"{filename}" removed because "{new_filename}" exists')
        except Exception as e:
            print(f'Error occured on "{filename}"')
            raise e
