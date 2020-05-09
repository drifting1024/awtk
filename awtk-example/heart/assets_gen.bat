@rem ---------------------------------------------------------------------------------------------------
@rem һ�������AWTK_DIR��ֵ��SConstruct�ű���getAwtkRoot()�������õ����޸�ʱ��ע��
@rem ����˫���������⡢�ַ��������塢ͼƬ��UI�ȶ������ļ�(���е���assets_gen.py)                                   
@rem �����޸� AWTK_DIR =../../awtk Ϊ����awtk��Ӧ��Ŀ¼
@rem �ġ��޸ĸýű��е�forѭ��ΪӦ���ж�Ӧ����ԴĿ¼�������ж����ԴĿ¼��res_800_480��res_480_272�����޸�Ϊ��for %%i in (res_800_480, res_480_272) do (
@rem �塢python assets_gen.py %AWTK_DIR%/bin %%i/assets/raw %%i/assets/inc˵����
@rem    1 Ϊ�գ�
@rem      ��python assets_gen.py %AWTK_DIR%/bin %%i/assets/raw %%i/assets/inc���������⡢�ַ��������塢ͼƬ��UI�ȶ������ļ�
@rem    2 -style 
@rem      ��python assets_gen.py %AWTK_DIR%/bin %%i/assets/raw %%i/assets/inc -style��  ��������
@rem    3 -string
@rem      ��python assets_gen.py %AWTK_DIR%/bin %%i/assets/raw %%i/assets/inc -string�� �����ַ���
@rem    4 -font
@rem      ��python assets_gen.py %AWTK_DIR%/bin %%i/assets/raw %%i/assets/inc -font��   ��������
@rem    5 -image
@rem      ��python assets_gen.py %AWTK_DIR%/bin %%i/assets/raw %%i/assets/inc -image��  ����ͼƬ
@rem    6 -ui
@rem      ��python assets_gen.py %AWTK_DIR%/bin %%i/assets/raw %%i/assets/inc -ui��     ����ui�ļ�	
@rem ---------------------------------------------------------------------------------------------------

@set AWTK_DIR=../../awtk
for %%i in (res) do (
  python assets_gen.py %AWTK_DIR%/bin %%i/assets/default/raw %%i/assets/default/inc
  python assets_c_gen.py %%i/assets
)

