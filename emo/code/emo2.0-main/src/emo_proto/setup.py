from setuptools import setup

package_name = 'emo_proto'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],

    install_requires=['setuptools'],
    zip_safe=True,

    author='Michael Azzopardi',
    author_email='michael.azzopardi@creative-innovation.net',
    maintainer='Michael Azzopardi',
    maintainer_email='michael.azzopardi@creative-innovation.net',
    
    keywords=['ROS','ROS2'],    
    classifiers=[
        'Intended Audience :: Developers',
        'License :: OSI Approved :: Apache Software Licencse',
        'Programming Language :: Python',
        'Topic :: Software Development',
    ],

    description='EMO 2.0 prototyping package for testing concepts and constructs.',
    license='Apache License 2.0',
    tests_require=['pytest'],
    
    entry_points={
        'console_scripts': [
            'proto = emo_proto.emo_proto_publisher:main',
        ],
    },

    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    
)
