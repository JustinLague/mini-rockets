import React from "react"
import { Line } from "react-chartjs-2"

class Graphs extends React.Component {


    shouldComponentUpdate(nextProps, nextState){
        return nextProps.labels.length !== this.props.labels.length
    }

    render() {
        return (
            <React.Fragment>
                <section className='col-span-2 max-h-72'>
                    <Line
                        datasetIdKey='xz'
                        options={{
                            ...this.props.baseOptions,
                            plugins: {
                                title: {
                                    display: true,
                                    text: "Altitude",
                                },
                            },
                        }}
                        data={{
                            labels: this.props.labels,
                            datasets: [this.props.dataset[9]],
                        }}
                    />
                </section>
                <section className=''>
                    <Line
                        datasetIdKey='xz'
                        options={{
                            ...this.props.baseOptions,
                            plugins: {
                                title: {
                                    display: true,
                                    text: "Temperature",
                                },
                            },
                        }}
                        data={{
                            labels: this.props.labels,
                            datasets: [this.props.dataset[10]],
                        }}
                    />
                </section>
                <section className=''>
                    <Line
                        datasetIdKey='xz'
                        options={{
                            ...this.props.baseOptions,
                            plugins: {
                                title: {
                                    display: true,
                                    text: "Pressure",
                                },
                            },
                        }}
                        data={{
                            labels: this.props.labels,
                            datasets: [this.props.dataset[11]],
                        }}
                    />
                </section>
                <section className=''>
                    <Line
                        datasetIdKey='xz'
                        options={{
                            ...this.props.baseOptions,
                            plugins: {
                                title: {
                                    display: true,
                                    text: "X Axis",
                                },
                            },
                        }}
                        data={{
                            labels: this.props.labels,
                            datasets: [this.props.dataset[3], this.props.dataset[0], this.props.dataset[6]],
                        }}
                    />
                </section>
                <section className=''>
                    <Line
                        datasetIdKey='y'
                        options={{
                            ...this.props.baseOptions,
                            plugins: {
                                title: {
                                    display: true,
                                    text: "Y Axis",
                                },
                            },
                        }}
                        data={{
                            labels: this.props.labels,
                            datasets: [this.props.dataset[4], this.props.dataset[1], this.props.dataset[7]],
                        }}
                    />
                </section>
                <section className=''>
                    <Line
                        datasetIdKey='xz'
                        options={{
                            ...this.props.baseOptions,
                            plugins: {
                                title: {
                                    display: true,
                                    text: "Z Axis",
                                },
                            },
                        }}
                        data={{
                            labels: this.props.labels,
                            datasets: [this.props.dataset[5], this.props.dataset[2], this.props.dataset[8]],
                        }}
                    />
                </section>
            </React.Fragment>
        )
    }
}

export default Graphs
